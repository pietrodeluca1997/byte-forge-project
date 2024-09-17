#include <algorithm>

#include "system.hpp"

using std::vector;
using std::remove_if;

void System::AddEntity(Entity entity)
{
    entities.push_back(entity);
}

void System::RemoveEntity(Entity entity)
{
    entities.erase(remove_if(entities.begin(), entities.end(), [&entity](Entity other) {
        return entity == other;
    }), entities.end());
}

vector<Entity> System::GetEntities()
{
    return entities;
}

const ComponentSignature& System::GetRequiredComponentSignature() const
{
    return requiredComponentSignature;
}
