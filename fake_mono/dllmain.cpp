// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "mono_wrapper/functions.h"

namespace
{
    optional<mono_wrapper::functions_t> g_mono_functions;
}

mono_wrapper::functions_t const &mono_functions()
{
    if (!g_mono_functions)
        throw std::runtime_error("mono functions not loaded");

    return *g_mono_functions;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	if (!g_mono_functions)
    {
        size_t const filename_size = 1024;
        char filename[filename_size];
        GetModuleFileNameA(hModule, filename, filename_size);
        fs::path dll_path(filename);
        auto real_dll_path = dll_path.parent_path() / "_mono.dll";
        
        HMODULE real_dll = LoadLibraryA(real_dll_path.string().c_str());
        g_mono_functions = mono_wrapper::load_mono_functions_from_dll(real_dll);
    }
    
    
    
    switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
        {
            break;
        }

	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

