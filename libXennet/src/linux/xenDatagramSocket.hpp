#ifndef DATAGRAMSOCKET_HPP
#define DATAGRAMSOCKET_HPP

#include "../xenMain.hpp"
#ifdef LINUX_OS

#include "xenSocketAddress.h"
#include "xenPacket.h"
#include "../xenDatagramSocketBase.hpp"

//! The Xennet namespace.
/*!
    The Xennet namespace contains all of the classes and functions in the library.
*/
namespace Xennet
{

    class DatagramSocket : public DatagramSocketBase, public SocketAddress
    {
    public:
        /** Default constructor */
        DatagramSocket(int port);
        /** Default destructor */
        virtual ~DatagramSocket();
        int getPort(void);
        bool isError(void);
        bool resetError(void);
        bool setTimeout(int seconds);
        bool connectSocket();
        bool closeSocket(void);
        bool sendData(Packet* data);
        bool sendData(std::string data);
        Packet* readData();
        std::string readDataAsString();
    protected:
        bool Error;
        int numRead;
        unsigned short int serverPort;
        int socketDescriptor;
        struct sockaddr_in serverAddress;
        struct timeval timeVal;
        fd_set readSet;
        char c;
        const int MAX_LINE;
        const int LINE_ARRAY_SIZE;
    private:
    };

} // namespace Xennet

#endif // LINUX_OS
#endif // DATAGRAMSOCKET_HPP
