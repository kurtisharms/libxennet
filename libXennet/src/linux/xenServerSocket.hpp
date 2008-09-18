#ifndef SERVERSOCKET_HPP
#define SERVERSOCKET_HPP

#include "../xenMain.hpp"
#ifdef LINUX_OS

#include "xenSocketAddress.h"
#include "xenPacket.h"
#include "../xenServerSocketBase.hpp"

namespace Xennet
{

    class ServerSocket : public ServerSocketBase
    {
    public:
        /** Default constructor */
        ServerSocket();
        ServerSocket(int port, int maxClients);
        /** Default destructor */
        virtual ~ServerSocket();
        int getPort(void);
        bool isError(void);
        bool resetError(void);
        bool bindSocket(void);
        bool acceptConnections(void);
        bool receiveData(Packet* data);
        bool receiveDataAsString(std::string* strData);
        bool sendData(Packet* data);
        bool sendData(std::string data);
    protected:
        bool Error;
        int maxConnections;
        int listenSocket, connectSocket, i;
        unsigned short int listenPort;
        socklen_t clientAddressLength;
        struct sockaddr_in clientAddress, serverAddress;
        char line[DEFAULT_MAX_DATA_SIZE+1];
    };

} // namespace Xennet

#endif // LINUX_OS
#endif // SERVERSOCKET_HPP
