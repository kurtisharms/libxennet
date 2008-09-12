#include "xenSocket.hpp"

#ifdef LINUX_OS

namespace Xennet
{

    Socket::Socket(int port)
    {
        Error = false;

        if (port > 0)
        {
            serverPort = port;
        }
        else
        {
            Error = true;
            serverPort = 80;
        }

        socketDescriptor = socket(AF_INET, SOCK_STREAM, 0);
        if (socketDescriptor < 0)
        {
            Error = true;
        }
    }

    Socket::~Socket()
    {
        close(socketDescriptor);
    }

    int Socket::getPort(void)
    {
        return serverPort;
    }

    bool Socket::isError(void)
    {
        return Error;
    }

    bool Socket::resetError(void)
    {
        Error = false;
        return true;
    }

    bool Socket::connectSocket()
    {
        //std::cout << "In connectSocket(SocketAddress* address)" <<std::endl;
        //hostInfo = address->getAddressStruct();
        //std::cout << "Got hostInfo from address->getAddressStruct()" <<std::endl;

        serverAddress.sin_family = hostInfo->h_addrtype;
        //std::cout << "Assigned serverAddress hostinfo" <<std::endl;
        memcpy((char *) &serverAddress.sin_addr.s_addr,
               hostInfo->h_addr_list[0], hostInfo->h_length);
        //std::cout << "memcpy opertaion to serverAddress and hostinfo" <<std::endl;
        serverAddress.sin_port = htons(serverPort);
        //std::cout << "Assigned serverAddress the serverPort as " << serverAddress.sin_port <<std::endl;

        if (connect(socketDescriptor,
                    (sockaddr *) &serverAddress,
                    sizeof(serverAddress)) < 0)
        {
            //std::cerr << "Unable to connect to address from Socket! Returning!" <<std::endl;
            Error = true;
            return false;
        }
        //std::cout << "Returning from connectSocket(SocketAddress* address)\n" <<std::endl;
        return true;
    }

    bool Socket::closeSocket(void)
    {
        close(socketDescriptor);
        return true;
    }

    bool Socket::setCallBack(void (*func)(Packet*))
    {
        PassBack = func;
        if (PassBack != NULL)
        {
            return true;
        }
        else
        {
            Error = true;
            return false;
        }
    }

    bool Socket::sendData(Packet* data)
    {
        //std::cout << "In Socket::sendData(Packet* data)" <<std::endl;
        //std::cout << "Create charBuffer with getMaxDataSize()" <<std::endl;
        char charBuffer[getMaxDataSize()];
        //std::cout << "Copy data to charBuffer" <<std::endl;
        strcpy(charBuffer,data->getData().c_str());
        //std::cout << "Send data" <<std::endl;
        if (send(socketDescriptor, charBuffer, strlen(charBuffer) + 1, 0) < 0)
        {
            Error = true;
            //std::cerr << "Error in sending data to server. Closing socket and exiting function!" <<std::endl;
            close(socketDescriptor);
            //std::cerr << "Socket closed. Aborting sendData function!\n" <<std::endl;
            return false;
        }
        //std::cout << "Returning from Socket::sendData(Packet* data)\n" <<std::endl;
        return true;
    }

    bool Socket::sendData(std::string data)
    {
        Packet *p = new Packet(data);
        sendData(p);
        return false;
    }

} // namespace Xennet

#endif // LINUX_OS
