#include "registry.hpp"
#include "core_systems/logger/logger.hpp"

Entity Registry::CreateEntity()
{
    int entityId = totalNumberOfEntities++;
    
    Entity entity(entityId);

    entitiesToBeAdded.insert(entity);

    if (entityId >= static_cast<int>(entityComponentSignatures.size()))
    {
        entityComponentSignatures.resize(entityId + 1);
    }

    return entity;
}

void Registry::Update()
{
    for (auto entity : entitiesToBeAdded) 
    {   
        const auto entityId = entity.GetId();

        const auto &entityComponentSignature = entityComponentSignatures[entityId];

        for (auto& system : systemsMap) 
        {
            const auto& systemComponentSignature = system.second->GetRequiredComponentSignature();

            bool isInterested = (entityComponentSignature & systemComponentSignature) == systemComponentSignature;

            if (isInterested) 
            {
                system.second->AddEntity(entity);
            }
        }
    }

    entitiesToBeAdded.clear();
}
