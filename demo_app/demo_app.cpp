#include "stdafx.h"
#include "mono_wrapper/functions.h"
#include "mono_wrapper/object_base.h"


int main(int argc, char* argv[])
{
    fs::path game_dir("C:\\my\\unity\\proj1\\proj1\\build\\1_Data");

    fs::path managed_dir = game_dir / "Managed";
    fs::path mono_dir = game_dir / "Mono";
    fs::path dll_path = mono_dir / "_mono.dll";

    HMODULE dll = LoadLibraryA(dll_path.string().c_str());
    auto f = make_shared<mono_wrapper::functions_t>(mono_wrapper::load_mono_functions_from_dll(dll));

    f->mono_set_dirs(managed_dir.string().c_str(), (game_dir / "Mono/etc").string().c_str());
    
    {
        std::stringstream ss;
        ss << managed_dir.string() << ";" << mono_dir.string();
        f->mono_set_assemblies_path(ss.str().c_str());
    }

    MonoDomain* domain = f->mono_jit_init("My domain");

	return 0;
}

