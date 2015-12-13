//LinearAllocator.hpp
#pragma once
#include "IAllocator.hpp"
#include <memory>
namespace MNAlloc{

    template <size_t size>
    class StackAllocator: public IAllocator
    {
    private:
        unsigned char m_block[size];
        size_t m_cursor;
    public:

        StackAllocator()
        {
            m_cursor = 0;
        }

        Block allocate(size_t block_size) override
        {
            Block x;
            x.ptr = nullptr;

            if(block_size + m_cursor < size)
            {
                x.ptr = (m_block)+m_cursor;
                m_cursor += block_size;
                x.size = block_size;
            }

            return x;
         }

         void deallocate(Block block) override{
             //you cannot deallocate memory individually
         }

         void deallocateAll() override{
             m_cursor = 0;
         }

         ~StackAllocator(){
             m_cursor = 0;
         }

    };

}
