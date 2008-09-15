#include "xenServerSocket.hpp"

#ifdef LINUX_OS

namespace Xennet
{

    ServerSocket::ServerSocket()
    {
        //ctor
    }

    ServerSocket::ServerSocket(int port, int maxClients)
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

        listenSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (listenSocket < 0)
        {
            Error = true;
        }
        if (maxClients < 1)
        {
            maxConnections = 1;
        }
    }

    ServerSocket::~ServerSocket()
    {
        //dtor
    }

    int ServerSocket::getPort(void)
    {
        return listenPort;
    }

    bool ServerSocket::isError(void)
    {
        return Error;
    }

    bool ServerSocket::resetError(void)
    {
        Error = false;
        return true;
    }

    bool ServerSocket::bindSocket(void)
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

    bool ServerSocket::acceptConnection(void)
    {
        clientAddressLength = sizeof(clientAddress);
        connectSocket = accept(listenSocket,
                               (struct sockaddr *) &clientAddress,
                               &clientAddressLength);
        if (connectSocket < 0)
        {
            Error = 1;
            return false;
        }
        return true;
    }

     bool ServerSocket::sendData(Packet* data)
    {
        //std::cout << "In Socket::sendData(Packet* data)" <<std::endl;
        //std::cout << "Create charBuffer with getMaxDataSize()" <<std::endl;
        char charBuffer[getMaxDataSize()];
        //std::cout << "Copy data to charBuffer" <<std::endl;
        strcpy(charBuffer,data->getData().c_str());
        //std::cout << "Send data" <<std::endl;
        if (send(connectSocket, charBuffer, strlen(charBuffer) + 1, 0) < 0)
        {
            Error = true;
            return false;
        }
        //std::cout << "Returning from Socket::sendData(Packet* data)\n" <<std::endl;
        return true;
    }

    bool ServerSocket::sendData(std::string data)
    {
        Packet *p = new Packet(data);
        sendData(p);
        return false;
    }

} // namespace Xennet

#endif // LINUX_OS
