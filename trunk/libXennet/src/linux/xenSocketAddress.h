#ifndef XENSOCKETADDRESS_H
#define XENSOCKETADDRESS_H
#include "../xenMain.hpp"
#ifdef LINUX_OS

#include "../xenSocketAddressBase.hpp"

namespace Xennet
{

    class SocketAddress : public SocketAddressBase
    {
    public:
        struct hostent *he;
        /** Default constructor */
        SocketAddress();
        /** Default destructor */
        virtual ~SocketAddress();
        bool setIPAddress(const char* cp);
        bool setHostName(const char* name);
        bool isAddressNull(void);
        char* getAddressName(void);
        char* getAddressIP(void);
        hostent* getAddressStruct(void);

    protected:
    private:
        int i;
        struct in_addr **addr_list;
        struct in_addr addr;
    };

} // namespace Xennet

#endif // LINUX_OS
#endif // XENSOCKETADDRESS_H
