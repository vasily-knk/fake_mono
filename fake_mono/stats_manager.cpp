#include "stdafx.h"
#include "stats_manager.h"

#include "mono_wrapper/transform.h"
#include "mono_wrapper/Vector3.h"
#include "mono_wrapper/GameObject.h"
#include "mono_wrapper/String.h"

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
        auto &data = find_gameobject_data(go);
        data.pos = *pos;
    }

private:
    gameobject_data &find_gameobject_data(mono_wrapper::GameObject_ptr go)
    {
        auto id = go->GetInstanceID();

        auto it = data_.find(id);
        if (it == data_.end())
        {
            gameobject_data data;
            data.name = go->get_name()->to_utf8();

            it = data_.emplace(id, data).first;
        }

        return it->second;
    }

private:
    std::map<int32_t, gameobject_data> data_;
};

stats_manager_ptr stats_manager_instance()
{
    static auto p = make_shared<stats_manager_impl>();
    return p;
}