#include "xenServerSocketBase.hpp"

namespace Xennet
{

    ServerSocketBase::ServerSocketBase()
    {
        setMaxDataSize(DEFAULT_MAX_DATA_SIZE);
    }

    ServerSocketBase::~ServerSocketBase()
    {
        //dtor
    }

    void ServerSocketBase::setMaxDataSize(int maxSize)
    {
        maxDataSize = maxSize;
    }

    int ServerSocketBase::getMaxDataSize(void)
    {
        if(maxDataSize < 1)
            return DEFAULT_MAX_DATA_SIZE;
        else
            return maxDataSize;
    }

} // namespace Xennet
