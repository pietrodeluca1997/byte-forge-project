#pragma once

#include <vector>
#include <memory>

#include "gameplay_foundations/ecs/entities/ecs_entity.hpp"
#include "gameplay_foundations/ecs/components/ecs_component.hpp"

namespace BFE::GameplayFoundations::ECS
{
    class ECSRegistry;

    class ECSSystem 
    {
        private:
            EntityComponentSignature requiredEntityComponentSignature;

            std::vector<ECSEntity> systemEntities;

        public:
            ECSSystem(const ECSRegistry &registry) : ecsRegistryReference(registry) {}
            ~ECSSystem() = default;

            void AddEntity(ECSEntity entity);
            void RemoveEntity(ECSEntity entity);
            std::vector<ECSEntity> GetEntities();

            const EntityComponentSignature& GetRequiredEntityComponentSignature() const;

            template <typename TComponentType> void RequireComponent();

            const ECSRegistry& ecsRegistryReference;
    };

    template <typename TECSComponentType>
    void ECSSystem::RequireComponent()
    {
        const int componentId = ECSComponent<TECSComponentType>::GetId();
        requiredEntityComponentSignature.set(componentId, true);
    }
}