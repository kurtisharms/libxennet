#ifndef SOCKETADDRESSBASE_HPP
#define SOCKETADDRESSBASE_HPP

#include "xenMain.hpp"

namespace Xennet
{

    class SocketAddressBase
    {
    public:
        /** Default constructor */
        SocketAddressBase() {}
        /** Default destructor */
        virtual ~SocketAddressBase() {}
        virtual bool setIPAddress(const char* cp) = 0;
        virtual bool setHostName(const char* name) = 0;
        virtual bool isAddressNull(void) = 0;
        virtual char* getAddressName(void) = 0;
        virtual char* getAddressIP(void) = 0;

    protected:
    private:
    };

} // namespace Xennet

#endif // SOCKETADDRESSBASE_HPP
