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
        return maxDataSize;
    }

} // namespace Xennet
