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
    class ECSRegistry 
    {
        private:
            int totalNumberOfEntities = 0;
            std::set<ECSEntity> entitiesToBeAdded;

            std::vector<std::shared_ptr<BFE::CoreSystems::Memory::IObjectPool>> componentObjectPool;

            std::vector<EntityComponentSignature> entityComponentSignatures;

            std::unordered_map<std::type_index, std::shared_ptr<ECSSystem>> systemsMap;

        public:
            ECSRegistry() = default;
            ~ECSRegistry() = default;

            template <typename TECSSystem, typename... TECSSystemArgs> void AddSystem(TECSSystemArgs &&...args);
            template <typename TECSSystem> std::shared_ptr<TECSSystem> GetSystem() const;

            ECS::ECSEntity CreateEntity();

            void Update();

            template <typename TECSComponent, typename ...TECSComponentArgs> void AddComponent(ECSEntity entity, TECSComponentArgs&& ...args);
            template <typename TECSComponent> TECSComponent& GetComponent(ECS::ECSEntity entity) const;
    };

    template <typename TECSSystem, typename... TECSSystemArgs>
    inline void ECSRegistry::AddSystem(TECSSystemArgs &&...args)
    {
        std::shared_ptr<TECSSystem> newSystem = std::make_shared<TECSSystem>(*this, std::forward<TECSSystemArgs>(args)...);
        systemsMap.insert(std::make_pair(std::type_index(typeid(TECSSystem)), newSystem));
    }

    template <typename TECSSystem>
    std::shared_ptr<TECSSystem> ECSRegistry::GetSystem() const
    {
        auto pair = systemsMap.find(std::type_index(typeid(TECSSystem)));
        return std::static_pointer_cast<TECSSystem>(pair->second);
    }

    template <typename TECSComponent, typename... TECSComponentArgs>
    inline void ECSRegistry::AddComponent(ECSEntity entity, TECSComponentArgs &&...args)
    {
        const int componentId = ECSComponent<TECSComponent>::GetId();

        const int entityId = entity.GetId();

        if (componentId >= static_cast<int>(componentObjectPool.size()))
        {
            componentObjectPool.resize(componentId + 1, nullptr);
        }

        if (!componentObjectPool[componentId])
        {
            std::shared_ptr<BFE::CoreSystems::Memory::ObjectPool<TECSComponent>> newComponentPool = std::make_shared<BFE::CoreSystems::Memory::ObjectPool<TECSComponent>>();
            componentObjectPool[componentId] = newComponentPool;
        }

        std::shared_ptr<BFE::CoreSystems::Memory::ObjectPool<TECSComponent>> componentPool = std::static_pointer_cast<BFE::CoreSystems::Memory::ObjectPool<TECSComponent>>(componentObjectPool[componentId]);

        if (entityId >= componentPool->GetSize()) 
        {
            componentPool->Resize(totalNumberOfEntities);
        }   

        TECSComponent newComponent(std::forward<TECSComponentArgs>(args)...);

        componentPool->Set(entityId, newComponent);

        entityComponentSignatures[entityId].set(componentId, true);
    }

    template <typename TECSComponent>
    TECSComponent& ECSRegistry::GetComponent(ECSEntity entity) const
    {
        const auto componentId = ECSComponent<TECSComponent>::GetId();
        const auto entityId = entity.GetId();
        auto componentPool = std::static_pointer_cast<BFE::CoreSystems::Memory::ObjectPool<TECSComponent>>(componentObjectPool[componentId]);
        return componentPool->Get(entityId);
    }
}