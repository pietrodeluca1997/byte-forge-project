#pragma once

class IComponent 
{
protected:
    static int nextId;    
};

template <typename T>
class Component : public IComponent
{
    static int GetId() 
    {
        static int id = nextId++;
        return id;
    }
};