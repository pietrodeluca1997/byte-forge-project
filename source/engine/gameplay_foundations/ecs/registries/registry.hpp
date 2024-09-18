#pragma once

#include <vector>
#include <unordered_map>
#include <typeindex>
#include <set>
#include <memory>

#include "gameplay_foundations/ecs/systems/system.hpp"
#include "core_systems/memory/object_pool.hpp"
#include "core_systems/logger/logger.hpp"

class Registry 
{
    private:
        int numberOfEntities = 0;
        std::set<Entity> entitiesToBeAdded;

        std::vector<std::shared_ptr<IObjectPool>> componentObjectPool;

        std::vector<ComponentSignature> entityComponentSignatures;

        std::unordered_map<std::type_index, std::shared_ptr<System>> systemsMap;

    public:
        Registry() = default;
        ~Registry() = default;

        template <typename TSystem, typename... TSystemArgs>
        void AddSystem(TSystemArgs &&...args);
        template <typename TSystem> std::shared_ptr<TSystem> GetSystem() const;

        Entity CreateEntity();

        void Update();

        template<typename TComponent, typename ...TComponentArgs> void AddComponent(Entity entity, TComponentArgs&& ...args);
};

template <typename TSystem, typename... TSystemArgs>
inline void Registry::AddSystem(TSystemArgs &&...args)
{
    std::shared_ptr<TSystem> newSystem = std::make_shared<TSystem>(std::forward<TSystemArgs>(args)...);
    systemsMap.insert(std::make_pair(std::type_index(typeid(TSystem)), newSystem));
}

template <typename TSystem>
std::shared_ptr<TSystem> Registry::GetSystem() const
{
    auto pair = systemsMap.find(std::type_index(typeid(TSystem)));
    return std::static_pointer_cast<TSystem>(pair->second);
}

template <typename TComponent, typename... TComponentArgs>
inline void Registry::AddComponent(Entity entity, TComponentArgs &&...args)
{
    const int componentId = Component<TComponent>::GetId();

    const int entityId = entity.GetId();

    if (componentId >= static_cast<int>(componentObjectPool.size()))
    {
        componentObjectPool.resize(componentId + 1, nullptr);
    }

    if (!componentObjectPool[componentId])
    {
        std::shared_ptr<ObjectPool<TComponent>> newComponentPool = std::make_shared<ObjectPool<TComponent>>();
        componentObjectPool[componentId] = newComponentPool;
    }

    std::shared_ptr<ObjectPool<TComponent>> componentPool = std::static_pointer_cast<ObjectPool<TComponent>>(componentObjectPool[componentId]);

    if (entityId >= componentPool->GetSize()) 
    {
        componentPool->Resize(numberOfEntities);
    }   

    TComponent newComponent(std::forward<TComponentArgs>(args)...);

    componentPool->Set(entityId, newComponent);

    entityComponentSignatures[entityId].set(componentId, true);
}
