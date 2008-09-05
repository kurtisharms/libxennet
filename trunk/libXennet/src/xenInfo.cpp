#include "xenInfo.hpp"

namespace Xennet
{

    Info::Info()
    {
        //ctor
    }

    Info::~Info()
    {
        //dtor
    }

    std::string Info::getVersion()
    {
        return XENNET_LIB_VERSION;
    }

    std::string Info::getDescription()
    {
        return "Xennet Library is a Cross-Platform Network Interface providing high-level access to native Sockets, Network Classes and Network interfaces. Xennet also provides additional classes and functions for usability and additional networking features.";
    }

    std::string Info::getCopyright()
    {
        return "Xennet Library Copyright 2007-2008. All rights reserved.";
    }

} // namespace Xennet
