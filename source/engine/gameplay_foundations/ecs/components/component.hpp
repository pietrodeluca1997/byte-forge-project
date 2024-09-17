#pragma once

struct IComponent
{
    public:
        static int nextId;    
};

template <typename TComponentType>
struct Component : public IComponent
{
    public:
        static int GetId() 
        {
            static int id = nextId++;
            return id;
        }
};