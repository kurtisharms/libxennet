#include "xenSocketAddress.h"
#ifdef LINUX_OS

namespace Xennet
{

    SocketAddress::SocketAddress()
    {
        //ctor
    }

    SocketAddress::~SocketAddress()
    {
        //dtor
    }

    bool SocketAddress::setIPAddress(const char* cp)
    {
        inet_aton("66.94.230.32", &addr);
        he = gethostbyaddr(&addr, sizeof addr, AF_INET);
        return isAddressNull();

    }

    bool SocketAddress::setHostName(const char* name)
    {
        he = gethostbyname(name);
        return isAddressNull();
    }

    bool SocketAddress::isAddressNull(void)
    {
        if (he == NULL)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    char* SocketAddress::getAddressName(void)
    {
        if (he != NULL)
        {
            return he->h_name;
        }
        else
        {
            return "";
        }
    }

    char* SocketAddress::getAddressIP(void)
    {
        if (he != NULL)
        {
            return inet_ntoa(*(struct in_addr*)he->h_addr);
        }
        else
        {
            return "";
        }
    }

    hostent* SocketAddress::getAddressStruct(void)
    {
        return he;
    }

} // namespace Xennet

#endif // LINUX_OS
