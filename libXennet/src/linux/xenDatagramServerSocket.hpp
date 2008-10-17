#ifndef DATAGRAMSERVERSOCKET_HPP
#define DATAGRAMSERVERSOCKET_HPP

#include "../xenMain.hpp"
#ifdef LINUX_OS

#include "xenSocketAddress.h"
#include "xenPacket.h"
#include "../xenDatagramServerSocketBase.hpp"

//! The Xennet namespace.
/*!
    The Xennet namespace contains all of the classes and functions in the library.
*/
namespace Xennet
{

    class DatagramServerSocket : public DatagramServerSocketBase
    {
    public:
        /** Default constructor */
        DatagramServerSocket();
        /** Default destructor */
        virtual ~DatagramServerSocket();
        //! Recommended default constructor.
        /*! \param port The port on which the server listens.
            \param maxClients Specify the maximum allowable connections simutaneously for this ServerSocket
            \return null
        */
        DatagramServerSocket(int port, int maxClients);

        int getPort(void);
        bool isError(void);
        bool resetError(void);
        bool bindSocket(void);
        Packet* receiveData(void);
        bool receiveDataAsString(std::string& strBuffer);
        bool sendData(Packet* data);
        bool sendData(std::string data);
    protected:
        bool Error;
        int maxConnections;
        int listenSocket, i;
        unsigned short int listenPort;
        socklen_t clientAddressLength;
        struct sockaddr_in clientAddress, serverAddress;
    private:
    };

} // namespace Xennet

#endif // LINUX_OS
#endif // DATAGRAMSERVERSOCKET_HPP
