#include "stdafx.h"
#include "stats_manager.h"

#include "mono_wrapper/transform.h"
#include "mono_wrapper/Vector3.h"
#include "mono_wrapper/GameObject.h"
#include "mono_wrapper/String.h"
#include "mono_wrapper/Struct.h"

namespace
{
    struct gameobject_data
    {
        string name;
        mono_wrapper::Vector3 pos;
    };

}

struct stats_manager_impl
    : stats_manager
{

    void set_position(mono_wrapper::Transform_ptr transform, mono_wrapper::Vector3 const *pos) override
    {
        auto go = transform->get_gameObject();
        auto id = go->GetInstanceID();

        if (data_.count(id) == 0)
            create_gameobject(go);
        
        data_.at(id).pos = *pos;
    }

    void create_gameobject(mono_wrapper::GameObject_ptr go) override
    {
        auto id = go->GetInstanceID();

        gameobject_data data;
        data.name = go->get_name()->to_utf8();
        data.pos = go->get_transform()->get_position()->get_value<mono_wrapper::Vector3>();

        data_[id] = data;
    }
   

private:
    std::map<int32_t, gameobject_data> data_;
};

stats_manager_ptr stats_manager_instance()
{
    static auto p = make_shared<stats_manager_impl>();
    return p;
}