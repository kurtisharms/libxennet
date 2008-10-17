#include "xenDatagramServerSocket.hpp"

#ifdef LINUX_OS

namespace Xennet
{

    DatagramServerSocket::DatagramServerSocket()
    {
        //ctor
    }

    DatagramServerSocket::~DatagramServerSocket()
    {
        //dtor
    }

    DatagramServerSocket::DatagramServerSocket(int port, int maxClients)
    {
        Error = false;

        if (port > 0)
        {
            listenPort = port;
        }
        else
        {
            Error = true;
            listenPort = 80;
        }

        listenSocket = socket(AF_INET, SOCK_DGRAM, 0);
        if (listenSocket < 0)
        {
            Error = true;
        }
        if (maxClients < 1)
        {
            maxConnections = 1;
        }
    }

    int DatagramServerSocket::getPort(void)
    {
        return listenPort;
    }

    bool DatagramServerSocket::isError(void)
    {
        return Error;
    }

    bool DatagramServerSocket::resetError(void)
    {
        Error = false;
        return true;
    }

    bool DatagramServerSocket::bindSocket(void)
    {
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
        serverAddress.sin_port = htons(listenPort);

        if (bind(listenSocket,
                 (struct sockaddr *) &serverAddress,
                 sizeof(serverAddress)) < 0)
        {
            Error = true;
            return false;
        }
        listen(listenSocket, maxConnections);
        return true;
    }

    Packet* DatagramServerSocket::receiveData(void)
    {
//dummy function
        return 0;
    }

    bool DatagramServerSocket::receiveDataAsString(std::string& strBuffer)
    {
        clientAddressLength = sizeof(clientAddress);
        const int MAX_MSG = getMaxDataSize();
        const int LINE_ARRAY_SIZE = MAX_MSG+1;
        char charBuffer[LINE_ARRAY_SIZE];
        memset(charBuffer, 0x0, LINE_ARRAY_SIZE);
        std::cout << "Receive DATA" <<std::endl;
        if (recvfrom(listenSocket, charBuffer, MAX_MSG, 0,
                     (struct sockaddr *) &clientAddress,
                     &clientAddressLength) < 0)
        {
            std::cout << "Got character data set as: " << charBuffer <<std::endl;
            std::string strBuffer = charBuffer;
            std::cout << "Returning with data set as: " << strBuffer <<std::endl;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool DatagramServerSocket::sendData(Packet* data)
    {
        //std::cout << "In Socket::sendData(Packet* data)" <<std::endl;
        //std::cout << "Create charBuffer with getMaxDataSize()" <<std::endl;
        char charBuffer[getMaxDataSize()];
        //std::cout << "Copy data to charBuffer" <<std::endl;
        strcpy(charBuffer,data->getData().c_str());
        //std::cout << "Send data" <<std::endl;
        //if (send(connectSocket, charBuffer, strlen(charBuffer) + 1, 0) < 0)
        if (sendto(listenSocket, charBuffer, strlen(charBuffer) + 1, 0,
                   (struct sockaddr *) &clientAddress,
                   sizeof(clientAddress)) < 0)
        {
            Error = true;
            return false;
        }
        //std::cout << "Returning from Socket::sendData(Packet* data)\n" <<std::endl;
        return true;
    }

    bool DatagramServerSocket::sendData(std::string data)
    {
        Packet *p = new Packet(data);
        return sendData(p);
    }

} // namespace Xennet

#endif // LINUX_OS
