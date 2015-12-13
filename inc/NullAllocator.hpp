//NullAllocator.hpp
#pragma once
#include <IAllocator>
#include <cassert>
namespace MNAlloc{
    //your code goes here
    class NullAllocator : public IAllocator
    {
    public:

        Block allocate(size_t) override
        {
            Block x;
            x.size = 0;
            x.ptr = nullptr;
            return x;

        }
        
        void deallocate(Block x) override
        {
            assert(x.ptr == nullptr);
        }
    };
}
