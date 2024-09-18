#include <algorithm>

#include "system.hpp"

using std::vector;
using std::remove_if;

void System::AddEntity(Entity entity)
{
    systemEntities.push_back(entity);
}

void System::RemoveEntity(Entity entity)
{
    systemEntities.erase(remove_if(systemEntities.begin(), systemEntities.end(), [&entity](Entity other) {
        return entity == other;
    }), systemEntities.end());
}

vector<Entity> System::GetEntities()
{
    return systemEntities;
}

const ComponentSignature& System::GetRequiredComponentSignature() const
{
    return requiredComponentSignature;
}
