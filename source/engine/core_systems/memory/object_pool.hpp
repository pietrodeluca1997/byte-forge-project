#pragma once

#include <vector>

namespace BFE::CoreSystems::Memory
{
    class IObjectPool
    {
        public:
            virtual ~IObjectPool() {}
    };

    template <typename TInnerObject>
    class ObjectPool : public IObjectPool
    {
        private:
            std::vector<TInnerObject> innerData;

        public:
            ObjectPool(const int desiredSize = 5) { innerData.resize(desiredSize); }

            virtual ~ObjectPool() override = default;

            const bool IsEmpty() const { return innerData.empty(); }

            const int GetSize() const { return innerData.size(); }

            void Resize(const int newSize) { innerData.resize(newSize); }

            void Clear() { innerData.clear(); }

            void Add(TInnerObject object) { innerData.push_back(object); }

            void Set(const int index, TInnerObject object) { innerData[index] = object; }

            TInnerObject& Get(int index) { return static_cast<TInnerObject&>(innerData[index]); }

            TInnerObject& operator [](unsigned int index) { return innerData.at(index); }
    };
}