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

//! The Xennet namespace.
/*!
    The Xennet namespace contains all of the classes and functions in the library.
*/
namespace Xennet
{
    //! SocketBase is inherited by the OS-specific Socket class .
    class SocketBase
    {
    public:
        /*! Default constructor */
        SocketBase();
        /*! Default destructor */
        virtual ~SocketBase();
        //! Set Maximum Data size for transmission by SocketBase.
        virtual void setMaxDataSize(int maxSize);
        //! Get Maximim Data size for transmission by SocketBase.
        virtual int getMaxDataSize(void);

        //! Pure virtual function to be overrided.
        virtual int getPort(void) = 0;
        //! Pure virtual function to be overrided.
        virtual bool isError(void) = 0;
        //! Pure virtual function to be overrided.
        virtual bool resetError(void) = 0;
        //! Pure virtual function to be overrided.
        virtual bool connectSocket() = 0;
        //! Pure virtual function to be overrided.
        virtual bool closeSocket(void) = 0;
        //! Pure virtual function to be overrided.
        virtual bool sendData(Packet* data) = 0;
        //! Pure virtual function to be overrided.
        virtual bool sendData(std::string data) = 0;
        //! Pure virtual function to be overrided.
        virtual Packet* readData() = 0;
        //! Pure virtual function to be overrided.
        virtual std::string readDataAsString() = 0;
    protected:
        //! Protected integer to hold the maximum allowable data size.
        int maxDataSize;
    private:
    };

} // namespace Xennet

#endif // SOCKETBASE_HPP
