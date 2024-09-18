#include "ecs_registry.hpp"
#include "core_systems/logging/logger.hpp"

namespace BFE::GameplayFoundations::ECS 
{
    ECS::ECSEntity ECSRegistry::CreateEntity()
    {
        int entityId = totalNumberOfEntities++;
        
        ECS::ECSEntity entity(entityId);

        entitiesToBeAdded.insert(entity);

        if (entityId >= static_cast<int>(entityComponentSignatures.size()))
        {
            entityComponentSignatures.resize(entityId + 1);
        }

        return entity;
    }

    void ECSRegistry::Update()
    {
        for (auto entity : entitiesToBeAdded) 
        {   
            const auto entityId = entity.GetId();

            const auto &entityComponentSignature = entityComponentSignatures[entityId];

            for (auto& system : systemsMap) 
            {
                const auto& systemComponentSignature = system.second->GetRequiredEntityComponentSignature();

                bool isInterested = (entityComponentSignature & systemComponentSignature) == systemComponentSignature;

                if (isInterested) 
                {
                    system.second->AddEntity(entity);
                }
            }
        }

        entitiesToBeAdded.clear();
    }
}
