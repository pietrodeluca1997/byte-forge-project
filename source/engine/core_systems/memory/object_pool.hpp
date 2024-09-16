#pragma once

#include <vector>

class IObjectPool 
{
public:
    virtual ~IObjectPool() {}
};

template <typename T>
class ObjectPool : IObjectPool
{
private:
    std::vector<T> data;

public:
    ObjectPool(const int desiredSize = 100) { data.resize(desiredSize); }

    virtual ~ObjectPool() = default;

    const bool isEmpty() const { return data.empty(); }

    const int GetSize() const { return data.size(); }

    void Resize(const int newSize) { return data.resize(newSize); }

    void Clear() { data.clear(); }

    void Add(T object) { data.push_back(object); }

    void Set(const int index, T object) { data[index] = object; }

    T& Get(int index) { return static_cast<T&>(data[index]); }

    T& operator [](unsigned int index) { return data[index]; }
};