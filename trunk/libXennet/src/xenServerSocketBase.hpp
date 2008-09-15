#ifndef SERVERSOCKETBASE_HPP
#define SERVERSOCKETBASE_HPP

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

    class ServerSocketBase
    {
    public:
        /** Default constructor */
        ServerSocketBase();
        /** Default destructor */
        virtual ~ServerSocketBase();
        virtual void setMaxDataSize(int maxSize);
        virtual int getMaxDataSize(void);
    protected:
        int maxDataSize;
    private:
    };

} // namespace Xennet

#endif // SERVERSOCKETBASE_HPP
