#include "xenDatagramServerSocketBase.hpp"

namespace Xennet
{


    DatagramServerSocketBase::DatagramServerSocketBase()
    {
        setMaxDataSize(DEFAULT_MAX_DATA_SIZE);
    }

    DatagramServerSocketBase::~DatagramServerSocketBase()
    {
        //dtor
    }

    void DatagramServerSocketBase::setMaxDataSize(int maxSize)
    {
        maxDataSize = maxSize;
    }

    int DatagramServerSocketBase::getMaxDataSize(void)
    {
        if (maxDataSize < 1)
            return DEFAULT_MAX_DATA_SIZE;
        else
            return maxDataSize;
    }

} // namespace Xennet
