#ifndef DATAGRAMSERVERSOCKETBASE_HPP
#define DATAGRAMSERVERSOCKETBASE_HPP

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

    class DatagramServerSocketBase
    {
    public:
        /** Default constructor */
        DatagramServerSocketBase();
        /** Default destructor */
        virtual ~DatagramServerSocketBase();
        virtual void setMaxDataSize(int maxSize);
        virtual int getMaxDataSize(void);
    protected:
        int maxDataSize;
    private:
    };


} // namespace Xennet

#endif // DATAGRAMSERVERSOCKETBASE_HPP
