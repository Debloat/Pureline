#ifndef _FIFO_ALLOCATOR_H_
#define _FIFO_ALLOCATOR_H_

#include <deque>

#include <unordered_map>

// Allocator implementation detail with simple FIFO grow-only pool.
// It relies on default CRT malloc/free.
class FifoAllocator
{
    public:
        FifoAllocator() = default;
        ~FifoAllocator() = default;

        void SetUp() {}
        void TearDown()
        {
            CleanUp(); // deallocate pooled blocks
        }

        void* Alloc(size_t size)
        {
            void* p = nullptr;
            if (PoolType& pool = pool_map_[size]; pool.size() < kWatermark)
            {
                p = ::malloc(size);
            }
            else
            {
                p = pool.front();
                pool.pop_front();
            }
            if (p != nullptr)
            {
                alloc_map_[p] = size;
            }
            return p;
        }
        void Free(void* p)
        {
            if (p == nullptr)
            {
                return;
            }
            AllocMapType::iterator it = alloc_map_.find(p);
            if (it == alloc_map_.end())
            {
                return;
            }
            size_t size = it->second;
            alloc_map_.erase(it);
            PoolMapType::iterator it2 = pool_map_.find(size);
            if (it2 == pool_map_.end())
            {
                return;
            }
            PoolType& pool = it2->second;
            pool.push_back(p);
        }

    private:
        void CleanUp()
        {
            auto it = pool_map_.begin();
            auto end = pool_map_.end();
            for (; it != end; ++it)
            {
                PoolType& pool = it->second;
                auto it2 = pool.begin();
                auto end2 = pool.end();
                for (; it2 != end2; ++it2)
                {
                    ::free(*it2);
                }
                pool.clear();
            }
            pool_map_.clear();
        }

        using PoolType = std::deque<void *>;
        using PoolMapType = std::unordered_map<size_t, PoolType>;
        using AllocMapType = std::unordered_map<void *, size_t>;

        static const size_t kWatermark = 4; // FIFO enforcement level

        PoolMapType pool_map_;
        AllocMapType alloc_map_;
};

#endif // _FIFO_ALLOCATOR_H_
