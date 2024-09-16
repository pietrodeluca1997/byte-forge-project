#pragma once

#include <vector>
#include "core_systems/memory/object_pool.hpp"

class Register 
{
private:
    int numberOfEntities = 0;

    std::vector<IObjectPool*> componentObjectPool;
};