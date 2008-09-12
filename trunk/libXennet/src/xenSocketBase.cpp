#include "xenSocketBase.hpp"

namespace Xennet
{

    SocketBase::SocketBase()
    {
        setMaxDataSize(100);
    }

    SocketBase::~SocketBase()
    {
        //dtor
    }

    void SocketBase::setMaxDataSize(int maxSize)
    {
        maxDataSize = maxSize;
    }

    int SocketBase::getMaxDataSize(void)
    {
        return maxDataSize;
    }

} // namespace Xennet
