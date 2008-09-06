#include "xenPacket.h"
#ifdef LINUX_OS

namespace Xennet
{

    Packet::Packet()
    {
        //ctor
    }

    Packet::Packet(std::string data)
    {
        setData(data);
    }

    Packet::Packet(char* data)
    {
        setData(data);
    }

    Packet::~Packet()
    {
        //dtor
    }

    bool Packet::setData(std::string str)
    {
        strBuffer = str;
        return true;
    }

    std::string Packet::getData(void)
    {
        return strBuffer;
    }

    bool Packet::setData(char* data)
    {
        strBuffer = data;
        return true;
    }

    char* Packet::getCharData(void)
    {
        char* cl = 0;
        strcpy(cl,strBuffer.c_str());
        return cl;
    }

} // namespace Xennet

#endif // LINUX_OS
