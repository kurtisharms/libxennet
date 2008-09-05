#include "xenPacket.h"
#ifdef LINUX_OS

namespace Xennet
{

    Packet::Packet()
    {
        //ctor
    }

    Packet::~Packet()
    {
        //dtor
    }

    bool Packet::setData(std::string str)
    {
    }

    std::string Packet::getData(void)
    {
    }

    bool Packet::setData(char* data)
    {
        return true;
    }

    char* Packet::getCharData(void)
    {
    }

} // namespace Xennet

#endif // LINUX_OS
