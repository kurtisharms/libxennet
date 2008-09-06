#ifndef XENPACKET_H
#define XENPACKET_H
#include "../xenMain.hpp"
#ifdef LINUX_OS

#include "../xenPacketBase.hpp"

namespace Xennet
{

    class Packet : public PacketBase
    {
    public:
        /** Default constructor */
        Packet();
        Packet(std::string data);
        Packet(char* data);
        /** Default destructor */
        virtual ~Packet();
        bool setData(std::string str);
        std::string getData(void);
        bool setData(char* data);
        char* getCharData();
    protected:
    private:
    };

} // namespace Xennet

#endif // LINUX_OS
#endif // XENPACKET_H
