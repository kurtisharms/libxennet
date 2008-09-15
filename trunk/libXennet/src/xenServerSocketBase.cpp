#include "xenServerSocketBase.hpp"

namespace Xennet
{

    ServerSocketBase::ServerSocketBase()
    {
        //ctor
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
        return maxDataSize;
    }

} // namespace Xennet
