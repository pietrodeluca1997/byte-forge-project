#pragma once

#include <vector>
#include <unordered_map>
#include <typeindex>
#include <set>
#include <memory>

#include "gameplay_foundations/ecs/systems/ecs_system.hpp"
#include "core_systems/memory/object_pool.hpp"
#include "core_systems/logging/logger.hpp"

namespace BFE::GameplayFoundations::ECS 
{
    using BFE::CoreSystems::Memory::IObjectPool;
    using BFE::CoreSystems::Memory::ObjectPool;

    class ECSRegistry 
    {
        private:
            int totalNumberOfEntities = 0;
            std::set<ECSEntity> entitiesToBeAdded;

            std::vector<std::shared_ptr<IObjectPool>> componentObjectPool;

            std::vector<EntityComponentSignature> entityComponentSignatures;

            std::unordered_map<std::type_index, std::shared_ptr<ECSSystem>> systemsMap;

        public:
            ECSRegistry() = default;
            ~ECSRegistry() = default;

            template <typename TSystem, typename... TSystemArgs>
            void AddSystem(TSystemArgs &&...args);
            template <typename TSystem> std::shared_ptr<TSystem> GetSystem() const;

            ECS::ECSEntity CreateEntity();

            void Update();

            template <typename TComponent, typename ...TComponentArgs> void AddComponent(ECSEntity entity, TComponentArgs&& ...args);
            template <typename TComponent> TComponent& GetComponent(ECS::ECSEntity entity) const;
    };

    template <typename TSystem, typename... TSystemArgs>
    inline void ECSRegistry::AddSystem(TSystemArgs &&...args)
    {
        std::shared_ptr<TSystem> newSystem = std::make_shared<TSystem>(*this, std::forward<TSystemArgs>(args)...);
        systemsMap.insert(std::make_pair(std::type_index(typeid(TSystem)), newSystem));
    }

    template <typename TSystem>
    std::shared_ptr<TSystem> ECSRegistry::GetSystem() const
    {
        auto pair = systemsMap.find(std::type_index(typeid(TSystem)));
        return std::static_pointer_cast<TSystem>(pair->second);
    }

    template <typename TComponent, typename... TComponentArgs>
    inline void ECSRegistry::AddComponent(ECSEntity entity, TComponentArgs &&...args)
    {
        const int componentId = ECSComponent<TComponent>::GetId();

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
            componentPool->Resize(totalNumberOfEntities);
        }   

        TComponent newComponent(std::forward<TComponentArgs>(args)...);

        componentPool->Set(entityId, newComponent);

        entityComponentSignatures[entityId].set(componentId, true);
    }

    template <typename TComponent>
    TComponent &ECSRegistry::GetComponent(ECSEntity entity) const
    {
        const auto componentId = ECSComponent<TComponent>::GetId();
        const auto entityId = entity.GetId();
        auto componentPool = std::static_pointer_cast<ObjectPool<TComponent>>(componentObjectPool[componentId]);
        return componentPool->Get(entityId);
    }
}