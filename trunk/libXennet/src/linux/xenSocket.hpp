#ifndef XENSOCKET_HPP
#define XENSOCKET_HPP
#include "../xenMain.hpp"
#ifdef LINUX_OS

#include "xenSocketAddress.h"
#include "xenPacket.h"
#include "../xenSocketBase.hpp"

//! The Xennet namespace.
/*!
    The Xennet namespace contains all of the classes and functions in the library.
*/
namespace Xennet
{

    class Socket : public SocketBase, public SocketAddress
    {
    public:
        /** Default constructor */
        Socket(int port);
        /** Default destructor */
        virtual ~Socket();
        int getPort(void);
        bool isError(void);
        bool resetError(void);
        bool connectSocket();
        bool closeSocket(void);
        bool setCallBack(void (*func)(Packet*));
        bool sendData(Packet* data);
        bool sendData(std::string data);
        Packet* readData();
        std::string readDataAsString();
    protected:
        bool Error;
        unsigned short int serverPort;
        int socketDescriptor;
        struct sockaddr_in serverAddress;
        char c;
        //hostent *hostInfo;
        void (*PassBack)(Packet*);
    };

} // namespace Xennet

#endif // LINUX_OS
#endif // XENSOCKET_HPP
