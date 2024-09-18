#include <algorithm>

#include "ecs_system.hpp"

using std::vector;
using std::remove_if;

namespace BFE::GameplayFoundations::ECS
{
    void ECSSystem::AddEntity(ECSEntity entity)
    {
        systemEntities.push_back(entity);
    }

    void ECSSystem::RemoveEntity(ECSEntity entity)
    {
        systemEntities.erase(remove_if(systemEntities.begin(), systemEntities.end(), [&entity](ECSEntity other) {
            return entity == other;
        }), systemEntities.end());
    }

    vector<ECSEntity> ECSSystem::GetEntities()
    {
        return systemEntities;
    }

    const EntityComponentSignature &ECSSystem::GetRequiredEntityComponentSignature() const
    {
        return requiredEntityComponentSignature;
    }
}