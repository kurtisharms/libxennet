#ifndef SOCKETADDRESSBASE_HPP
#define SOCKETADDRESSBASE_HPP

#include "xenMain.hpp"

//! The Xennet namespace.
/*!
    The Xennet namespace contains all of the classes and functions in the library.
*/
namespace Xennet
{
    //! SocketAddressBase is inherited by the OS-specific SocketAddress class.
    class SocketAddressBase
    {
    public:
        /** Default constructor */
        SocketAddressBase() {}
        /** Default destructor */
        virtual ~SocketAddressBase() {}
        //! Pure virtual function to be overrided.
        virtual bool setIPAddress(const char* cp) = 0;
        //! Pure virtual function to be overrided.
        virtual bool setHostName(const char* name) = 0;
        //! Pure virtual function to be overrided.
        virtual bool isAddressNull(void) = 0;
        //! Pure virtual function to be overrided.
        virtual char* getAddressName(void) = 0;
        //! Pure virtual function to be overrided.
        virtual char* getAddressIP(void) = 0;
        //! Pure virtual function to be overrided.

    protected:
    private:
    };

} // namespace Xennet

#endif // SOCKETADDRESSBASE_HPP
