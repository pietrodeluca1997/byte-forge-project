#pragma once

#include <bitset>

constexpr unsigned int MAX_COMPONENTS = 32;
typedef std::bitset<MAX_COMPONENTS> ComponentSignature;

class Entity 
{ 
    private:
        int id;

    public:
        Entity(const int id) : id(id) {}
        Entity(const Entity& entity) = default;

        int GetId() const { return id; }

        // Operators overload
        Entity& operator =(const Entity& other) = default;
        bool operator ==(const Entity& other) const { return GetId() == other.GetId(); }
        bool operator !=(const Entity &other) const { return GetId() != other.GetId(); }
        bool operator <(const Entity &other) const { return GetId() < other.GetId(); }
        bool operator >(const Entity &other) const { return GetId() > other.GetId(); }
};