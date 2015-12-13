//Block.hpp
#pragma once
#include <stddef.h>

namespace MNAlloc{
    class Block{
    public:
        void* ptr;
        size_t size;
    };
}
