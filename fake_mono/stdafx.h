// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>


#include <cstdint>
#include <iostream>
#include <fstream>
#include <sstream>

#include <tuple>

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <map>

#include <string>
using std::string;