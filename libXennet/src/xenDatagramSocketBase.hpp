#ifndef DATAGRAMSOCKETBASE_HPP
#define DATAGRAMSOCKETBASE_HPP


#include "xenMain.hpp"

//! The Xennet namespace.
/*!
    The Xennet namespace contains all of the library classes and functions.
*/
namespace Xennet
{

    //! DatagramSocketBase is inherited by the OS-specific DatagramSocket class.
    class DatagramSocketBase
    {
    public:
        /** Default constructor */
        DatagramSocketBase();
        /** Default destructor */
        virtual ~DatagramSocketBase();
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

#endif // DATAGRAMSOCKETBASE_HPP
