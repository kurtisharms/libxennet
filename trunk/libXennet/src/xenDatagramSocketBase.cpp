#include "xenDatagramSocketBase.hpp"

namespace Xennet
{

    DatagramSocketBase::DatagramSocketBase()
    {
        setMaxDataSize(DEFAULT_MAX_DATA_SIZE);
    }

    DatagramSocketBase::~DatagramSocketBase()
    {
        //dtor
    }

    void DatagramSocketBase::setMaxDataSize(int maxSize)
    {
        maxDataSize = maxSize;
    }

    int DatagramSocketBase::getMaxDataSize(void)
    {
        return maxDataSize;
    }

} // namespace Xennet
