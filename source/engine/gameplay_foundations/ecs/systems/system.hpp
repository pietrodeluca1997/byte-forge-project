#pragma once

#include <vector>
#include <memory>

#include "gameplay_foundations/ecs/entities/entity.hpp"
#include "gameplay_foundations/ecs/components/component.hpp"

class System 
{
private:
    ComponentSignature requiredComponentSignature;

    std::vector<Entity> entities;

public:

    System() = default;
    ~System() = default;

    void AddEntity(Entity entity);
    void RemoveEntity(Entity entity);
    std::vector<Entity> GetEntities();

    const ComponentSignature& GetRequiredComponentSignature() const;

    template <typename TComponentType> void RequireComponent();
};

template <typename TComponentType>
void System::RequireComponent()
{
    const int componentId = Component<TComponentType>::GetId();
    requiredComponentSignature.set(componentId, true);
}