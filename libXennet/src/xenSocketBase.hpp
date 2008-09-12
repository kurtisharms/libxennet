#ifndef SOCKETBASE_HPP
#define SOCKETBASE_HPP

#include "xenMain.hpp"

namespace Xennet
{

    class SocketBase
    {
    public:
        /** Default constructor */
        SocketBase();
        /** Default destructor */
        virtual ~SocketBase();
        virtual void setMaxDataSize(int maxSize);
        virtual int getMaxDataSize(void);
    protected:
        int maxDataSize;
    private:
    };

} // namespace Xennet

#endif // SOCKETBASE_HPP
