#include "ecs_registry.hpp"

#include "core_systems/logging/logger.hpp"

namespace BFE::GameplayFoundations::ECS 
{
    ECSEntity ECSRegistry::CreateEntity()
    {
        int entityId = totalNumberOfEntities++;
        
        ECSEntity entity(entityId);

        entitiesToBeAdded.insert(entity);

        if (entityId >= static_cast<int>(entityComponentSignatures.size()))
        {
            entityComponentSignatures.resize(entityId + 1);
        }

        return entity;
    }

    void ECSRegistry::Update()
    {
        for (ECSEntity entity : entitiesToBeAdded) 
        {   
            const int entityId = entity.GetId();

            const EntityComponentSignature &entityComponentSignature = entityComponentSignatures[entityId];

            for (auto& system : systemsMap) 
            {
                const EntityComponentSignature& systemRequiredEntityComponentSignature = system.second->GetRequiredEntityComponentSignature();

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
