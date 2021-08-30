#pragma once

#include <memory>

/*
	TODO:
	* Make default pool size 1000;
*/

namespace memory 
{
    /**
     * Compute ceiling of log2 as a constexpr.
     */
    template <typename T>
    constexpr T log2ceil(T val) {
        T computedLog = 0;
        while (val > 0) {
            val >>= 1;
            ++computedLog;
        }
        return computedLog;
    } // log2ceil

    /**
     * @biref FixedAllocator aggregates an array of Chunks.
     * Whenever a request for memory comes and all existing Chunks are occupied,
     * FixedAllocator creates a new Chunk and appends it to the array. Then it
     * forwards the request to the new Chunk.
     */
    class FixedAllocator {
    private:
		/**
     	* Chunk - a simple POD representation of memory blocks in the pool.
     	* Each object of type Chunk contains and manages a chunk of memory
     	* consisting of an integral number of fixed-size blocks. Chunk contains
     	* logic that allows to allocate and deallocate memory blocks.
     	* 
     	* When there are no more blocks available in the chunk, the allocation
     	* function fails by returning zero.
     	*/
    	struct Chunk {
	    	void init(std::size_t blockSize,
	    			  unsigned char blocks);
	    	void* alloc(std::size_t blockSize);
	    	void dealloc(void* p, std::size blockSize);
	    	unsigned char* data_;
	    	unsigned char firstAvailableBlock_,
	    		blocksAvailable_;
    	};
    };


    /**
     * @brief SmallObjectAllocator provides general allocation and deallocation
     * functions. It holds several FixedAllocator objects, each specialized for 
     * allocating objects of one size. Depending on the number of bytes requsted,
     * it dispatches memory allocation requests to one of its FixedAllocators
     * or to the default operator new if the size requested is too large.
     */

    /**
     * @brief SmallObject offers encapsulated allocation services for 
     * c++ classes. Client objects benefit from specialized allocation by
     * simply deriving from SmallObject.
     */

	/**
	 * @brief Object pool data structure;
	 * 
	 * The pool can contain 1000+ objects, a user can specify desired number of 
	 * objects in the ctor, it can't be made less than 100 though.
	 */
	template <typename T>
	class ObjectPool
	{
	public:

		// ---------------------------------------------------------------------
        
		// ctor
		ObjectPool() {
			mBuffer = std::make_shared<std::vector<T>>();
		}

        // dtor
		~ObjectPool() {
			// noop, mBuffer will destroyed automatically as it is mamaged
			// by shared_ptr.
		}

		// ---------------------------------------------------------------------
		// public interface

		bool empty() const noexcept {
			// TODO: provide impl
			return true;
		}

		size_t available() const noexcept
		{
			// TODO: provide impl
			return 0;
		}

		std::shared_ptr<T> getObject() {
			// TODO: provide impl
			return nullptr;
		}
		void releaseObject(std::shared_ptr<T> object) {
			// TODO: provide impl
		}
		
	private:

		std::shared_ptr<std::vector<T>> mBuffer;
	}; // class ObjectPool
} // namespace memory
