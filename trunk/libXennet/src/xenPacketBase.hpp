#ifndef PACKETBASE_HPP
#define PACKETBASE_HPP

#include "xenMain.hpp"


namespace Xennet
{

    class PacketBase
    {
    public:
        /** Default constructor */
        PacketBase() {}
        PacketBase(std::string data) {}
        PacketBase(char* data) {}
        /** Default destructor */
        virtual ~PacketBase() {}
        virtual bool setData(std::string str)= 0;
        virtual std::string getData(void) = 0;
        virtual bool setData(char* data) = 0;
        virtual char* getCharData() = 0;
    protected:
        std::string strBuffer;
    private:
    };

} // namespace Xennet

#endif // PACKETBASE_HPP
