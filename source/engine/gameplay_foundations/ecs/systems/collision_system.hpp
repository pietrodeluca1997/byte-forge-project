#pragma once

#include "ecs_system.hpp"

namespace BFE::GameplayFoundations::ECS
{
    class CollisionSystem : public ECSSystem
    {
        private:
            bool CheckAABBCollision(double aX, double aY, double aW, double aH, double bX, double bY, double bW, double bH);
        public:
            CollisionSystem(const ECSRegistry &registry);

            void Update();
    };
}