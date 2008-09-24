#pragma once
#ifndef XENMAIN_HPP_INCLUDED
#define XENMAIN_HPP_INCLUDED

#ifdef linux
#define LINUX_OS
#endif

#ifdef LINUX_OS
#define OS_SRC "linux/"
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#endif // LINUX_OS

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <list>

//! Define XENNET_LIB_VERSION
#define XENNET_LIB_VERSION "0.0.1"
//! Define DEFAULT_MAX_DATA_SIZE
#define DEFAULT_MAX_DATA_SIZE 256

#endif // XENMAIN_HPP_INCLUDED
