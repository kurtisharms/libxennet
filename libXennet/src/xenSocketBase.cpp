#include "xenSocketBase.hpp"

namespace Xennet
{

    SocketBase::SocketBase()
    {
        setMaxDataSize(DEFAULT_MAX_DATA_SIZE);
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
        if (maxDataSize < 1)
            return DEFAULT_MAX_DATA_SIZE;
        else
            return maxDataSize;
    }

} // namespace Xennet
