#pragma once

#include "gameplay_foundations/ecs/entities/entity.hpp"
#include "gameplay_foundations/ecs/components/component.hpp"
#include <vector>

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

    template <typename TComponent> void RequireComponent();
};

template <typename TComponent>
void System::RequireComponent()
{
    const int componentId = Component<TComponent>::GetId();
    requiredComponentSignature.set(componentId, true);
}