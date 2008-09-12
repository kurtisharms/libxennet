#ifndef SOCKETBASE_HPP
#define SOCKETBASE_HPP

#include "xenMain.hpp"

#ifdef LINUX_OS
#include "linux/xenPacket.h"
#endif

#ifdef WIN32_OS
#include "win32/xenPacket.h"
#endif

#ifdef MAC_OS
#include "mac/xenPacket.h"
#endif

namespace Xennet
{

    class SocketBase
    {
    public:
        /** Default constructor */
        SocketBase();
        /** Default destructor */
        virtual ~SocketBase();
        virtual void setMaxDataSize(int maxSize);
        virtual int getMaxDataSize(void);

        virtual int getPort(void) = 0;
        virtual bool isError(void) = 0;
        virtual bool resetError(void) = 0;
        virtual bool connectSocket() = 0;
        virtual bool closeSocket(void) = 0;
        virtual bool sendData(Packet* data) = 0;
        virtual bool sendData(std::string data) = 0;
        virtual Packet* readData() = 0;
        virtual std::string readDataAsString() = 0;
    protected:
        int maxDataSize;
    private:
    };

} // namespace Xennet

#endif // SOCKETBASE_HPP
