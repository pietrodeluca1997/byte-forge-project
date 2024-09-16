#include "system.hpp"
#include <algorithm>

void System::AddEntity(Entity entity)
{
    entities.push_back(entity);
}

void System::RemoveEntity(Entity entity)
{
    entities.erase(std::remove_if(entities.begin(), entities.end(), [&entity](Entity other) {
        return entity == other;
    }), entities.end());
}

std::vector<Entity> System::GetEntities()
{
    return entities;
}

const ComponentSignature& System::GetRequiredComponentSignature() const
{
    return requiredComponentSignature;
}
