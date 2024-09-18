#pragma once

#include <bitset>

namespace BFE::GameplayFoundations::ECS 
{
    constexpr unsigned int MAX_ENTITY_COMPONENTS = 32;
    typedef std::bitset<MAX_ENTITY_COMPONENTS> EntityComponentSignature;

    class ECSEntity 
    { 
        private:
            int id;

        public:
            ECSEntity(const int id) : id(id) {}
            ECSEntity(const ECSEntity& entity) = default;

            int GetId() const { return id; }
            
            // Operators overload
            ECSEntity& operator =(const ECSEntity& other) = default;
            bool operator ==(const ECSEntity& other) const { return GetId() == other.GetId(); }
            bool operator !=(const ECSEntity &other) const { return GetId() != other.GetId(); }
            bool operator <(const ECSEntity &other) const { return GetId() < other.GetId(); }
            bool operator >(const ECSEntity &other) const { return GetId() > other.GetId(); }
    };
}