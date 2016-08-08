#include "stdafx.h"
#include "mono_wrapper/functions.h"


int main(int argc, char* argv[])
{
    fs::path dll_dir("C:\\my\\unity\\proj1\\proj1\\build\\1_Data\\Mono");
    fs::path dll_path = dll_dir / "_mono.dll";
    
    HMODULE dll = LoadLibraryA(dll_path.string().c_str());
    auto f = mono_wrapper::load_mono_functions_from_dll(dll);

	return 0;
}

