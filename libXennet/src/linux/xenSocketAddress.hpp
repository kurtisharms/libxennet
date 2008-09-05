#ifndef XENSOCKETADDRESS_HPP
#define XENSOCKETADDRESS_HPP

#include "xenMain.hpp"

namespace Xennet
{

    class SocketAddress
    {
    public:
        /** Default constructor */
        SocketAddress();
        /** Default destructor */
        virtual ~SocketAddress();

        struct hostent *he;

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

#endif // XENSOCKETADDRESS_HPP
