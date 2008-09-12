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
        inet_aton(cp, &addr);
        hostInfo = gethostbyaddr(&addr, sizeof addr, AF_INET);
        return isAddressNull();

    }

    bool SocketAddress::setIPAddress(std::string ip)
    {
        return setIPAddress(ip.c_str());
    }

    bool SocketAddress::setHostName(const char* name)
    {
        hostInfo = gethostbyname(name);
        return isAddressNull();
    }

    bool SocketAddress::isAddressNull(void)
    {
        if (hostInfo == NULL)
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
        if (hostInfo != NULL)
        {
            return hostInfo->h_name;
        }
        else
        {
            return "";
        }
    }

    char* SocketAddress::getAddressIP(void)
    {
        if (hostInfo != NULL)
        {
            return inet_ntoa(*(struct in_addr*)hostInfo->h_addr);
        }
        else
        {
            return "";
        }
    }

    /*hostent* SocketAddress::getAddressStruct(void)
    {
        return hostInfo;
    }*/

} // namespace Xennet

#endif // LINUX_OS
