#include "xenServerSocket.hpp"

#ifdef LINUX_OS

namespace Xennet
{

    ServerSocket::ServerSocket()
    {
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

    bool ServerSocket::acceptConnections(void)
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

    Packet* ServerSocket::receiveData(void)
    {
//dummy function
        return 0;
    }

    bool ServerSocket::receiveDataAsString(std::string& strBuffer)
    {
        const int MAX_MSG = getMaxDataSize();
        const int LINE_ARRAY_SIZE = MAX_MSG+1;
        char charBuffer[LINE_ARRAY_SIZE];
        memset(charBuffer, 0x0, LINE_ARRAY_SIZE);
        std::cout << "Receive DATA" <<std::endl;
        if (recv(connectSocket, charBuffer, MAX_MSG, 0) > 0)
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
        return sendData(p);
    }

} // namespace Xennet

#endif // LINUX_OS
