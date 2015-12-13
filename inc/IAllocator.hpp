//IAllocator.hpp
#pragma once
#include <stddef.h>
#include <Block.hpp>

namespace MNAlloc{
    class IAllocator{
    public:
        virtual Block allocate(size_t)=0;
        virtual void deallocate(Block)=0;

        //let's make it not mandtory to implement owns function
        virtual bool owns(Block){
            return false;
        }

        virtual ~ IAllocator(){}

        virtual void deallocateAll(){}
    };
}
