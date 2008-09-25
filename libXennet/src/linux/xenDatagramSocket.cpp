#include "xenDatagramSocket.hpp"

#ifdef LINUX_OS

namespace Xennet
{

    DatagramSocket::DatagramSocket(int port)
    {
        Error = false;
        MAX_LINE = getMaxDataSize();
        LINE_ARRAY_SIZE = MAX_LINE+3;
        FD_ZERO(&readSet);
        FD_SET(socketDescriptor, &readSet);
        timeVal.tv_sec = 60;

        if (port > 0)
        {
            serverPort = port;
        }
        else
        {
            Error = true;
            serverPort = 80;
        }

        socketDescriptor = socket(AF_INET, SOCK_DGRAM, 0);
        if (socketDescriptor < 0)
        {
            Error = true;
        }
    }

    DatagramSocket::~DatagramSocket()
    {
        close(socketDescriptor);
    }

    int DatagramSocket::getPort(void)
    {
        return serverPort;
    }

    bool DatagramSocket::isError(void)
    {
        return Error;
    }

    bool DatagramSocket::resetError(void)
    {
        Error = false;
        return true;
    }

    bool DatagramSocket::setTimeout(int seconds)
    {
        FD_ZERO(&readSet);
        FD_SET(socketDescriptor, &readSet);
        timeVal.tv_sec = seconds;
        return true;
    }

    bool DatagramSocket::connectSocket()
    {
        serverAddress.sin_family = hostInfo->h_addrtype;
        memcpy((char *) &serverAddress.sin_addr.s_addr,
               hostInfo->h_addr_list[0], hostInfo->h_length);
        serverAddress.sin_port = htons(serverPort);
        return true;
    }

    bool DatagramSocket::closeSocket(void)
    {
        close(socketDescriptor);
        return true;
    }

    bool DatagramSocket::sendData(Packet* data)
    {
        //std::cout << "In DatagramSocket::sendData(Packet* data)" <<std::endl;
        //std::cout << "Create charBuffer with getMaxDataSize()" <<std::endl;
        char charBuffer[LINE_ARRAY_SIZE];
        //std::cout << "Copy data to charBuffer" <<std::endl;
        strcpy(charBuffer,data->getData().c_str());
        //std::cout << "Send data" <<std::endl;
        if (sendto(socketDescriptor, charBuffer, strlen(charBuffer), 0,
                   (struct sockaddr *) &serverAddress,
                   sizeof(serverAddress)) < 0)
        {
            Error = 1;
            return false;
        }
        return true;
    }

    bool DatagramSocket::sendData(std::string data)
    {
        Packet *p = new Packet(data);
        sendData(p);
        return false;
    }

    std::string DatagramSocket::readDataAsString()
    {
        char charBuffer[LINE_ARRAY_SIZE];
        if (select(socketDescriptor+1, &readSet, NULL, NULL, &timeVal))
        {
            // Read the modified line back from the server.
            memset(charBuffer, 0x0, LINE_ARRAY_SIZE);  // Zero out the buffer.
            numRead = recv(socketDescriptor, charBuffer, MAX_LINE, 0);
            if (numRead < 0)
            {
                Error = true;
                return false;
            }

            std::cout << "Modified: " << charBuffer << "\n";
            std::string tmpStr = charBuffer;
            return tmpStr;
        }
        else
        {
            std::cout << "** Server did not respond within time limit.\n";
            return false;
        }
    }

    Packet* DatagramSocket::readData()
    {
        std::string tmpStr = readDataAsString();
        Packet* pack = new Packet(tmpStr);
        return pack;
    }

} // namespace Xennet

#endif // LINUX_OS
