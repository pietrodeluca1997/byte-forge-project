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
        for (ECS::ECSEntity entity : entitiesToBeAdded) 
        {   
            const int entityId = entity.GetId();

            const ECS::EntityComponentSignature &entityComponentSignature = entityComponentSignatures[entityId];

            for (auto& system : systemsMap) 
            {
                const ECS::EntityComponentSignature& systemRequiredEntityComponentSignature = system.second->GetRequiredEntityComponentSignature();

                bool isInterested = (entityComponentSignature & systemRequiredEntityComponentSignature) == systemRequiredEntityComponentSignature;

                if (isInterested) 
                {
                    system.second->AddEntity(entity);
                }
            }
        }

        if (entitiesToBeAdded.size() > 0) 
        {
            entitiesToBeAdded.clear();
        }
    }
}
