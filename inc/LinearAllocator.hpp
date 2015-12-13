//LinearAllocator.hpp
#pragma once
#include "IAllocator.hpp"
#include <memory>
namespace MNAlloc{

    template <size_t size>
    class LinearAllocator: public IAllocator
    {
    private:
        Block m_block;
        size_t m_cursor;
    public:

        LinearAllocator()
        {
            m_block.ptr = malloc(size);
            m_block.size = size;
            m_cursor = 0;
        }

        Block allocate(size_t block_size) override
        {
            Block x;
            x.ptr = nullptr;

            if(block_size + m_cursor < m_block.size)
            {
                x.ptr = ((unsigned char*)m_block.ptr)+m_cursor;
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

         ~LinearAllocator(){
             free(m_block.ptr);
         }

    };

}
