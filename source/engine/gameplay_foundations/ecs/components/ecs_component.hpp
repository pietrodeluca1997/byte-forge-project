#pragma once

namespace BFE::GameplayFoundations::ECS
{
    struct IECSComponent
    {
        public:
            static int nextComponentId;    
    };

    template <typename TECSComponentType>
    struct ECSComponent : public IECSComponent
    {
        public:
            static int GetId() 
            {
                static int id = nextComponentId++;
                return id;
            }
    };
}