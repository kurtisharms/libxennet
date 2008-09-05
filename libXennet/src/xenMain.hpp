#pragma once
#ifndef XENMAIN_HPP_INCLUDED
#define XENMAIN_HPP_INCLUDED

#ifdef linux
#define LINUX_OS
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#endif // linux

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <list>

#define XENNET_LIB_VERSION "0.0.1"

#endif // XENMAIN_HPP_INCLUDED
