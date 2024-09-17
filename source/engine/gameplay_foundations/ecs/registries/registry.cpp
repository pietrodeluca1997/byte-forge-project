#include "registry.hpp"
#include "core_systems/logger/logger.hpp"

Entity Registry::CreateEntity()
{
    int entityId = numberOfEntities++;
    
    Entity entity(entityId);

    entitiesToBeAdded.insert(entity);

    return entity;
}

void Registry::Update()
{
    
}
