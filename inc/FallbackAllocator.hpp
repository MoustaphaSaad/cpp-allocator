//FallbackAllocator.hpp
#pragma once
#include "IAllocator.hpp"

namespace MNAlloc{
    //can you see the code ?
//Yes
    template<class Primary, class Fallback>
    class FallbackAllocator: public IAllocator{
        Primary m_primary;
        Fallback m_fallback;
    public:
        Block allocate(size_t block_size) override
        {
            Block res = m_primary.allocate(block_size);
            if(!res.ptr)
                res = m_fallback.allocate(block_size);

            return res;
        }

        bool owns(Block blk)override
        {
            return m_primary.owns(blk) || m_fallback.owns(blk);
        }

        void deallocate(Block blk)override
        {
            if(m_primary.owns(blk))
                m_primary.deallocate(blk);
            else
                m_fallback.deallocate(blk);
        }
    };
}
