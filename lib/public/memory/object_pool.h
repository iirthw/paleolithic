#pragma once

#include <cassert>
#include <memory>

/*
	TODO:
	* Make default pool size 1000;
*/

namespace memory 
{
	/*
		Architecture of object allocator can be summarized as 4 layers:
		________________________________________________________________________
		| SmallObject : object-level services.								   |
		| ---------------------------------------------------------------------|
		| SmallObjAllocator : allocator of small objects of various sizes.     |
		| ---------------------------------------------------------------------|
		| FixedAllocator : allocator of only objects of one given size.        |
		| ---------------------------------------------------------------------|
		| Chunk : container of blocks of memory, with fixed upper limit of     |
		|         number of objects allocated.                                 |
		|______________________________________________________________________|
	*/

    /**
     * @biref FixedAllocator allocates and deallocates blocks of fixed size but
     * it is not limited to chunk's size. Its capacity is limited only by 
     * available memory.
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
     	* Chunk is made blockSize agnostic.
     	* 
     	* When there are no more blocks available in the chunk, the allocation
     	* function fails by returning zero.
     	* 
     	* The number of blocks is limited to a value that fits in an 
     	* unsigned char.
     	*/
    	struct Chunk {
    		// Initialize a chunk object.
    		void init(std::size_t blockSize, unsigned char blocks) {	    		
    			assert(blockSize > 0);
	    		data_ = new unsigned char[blockSize * blocks];
	    		firstAvailableBlock_ = 0;
	    		blocksAvailable_ = blocks;
	    		// Set the first byte of an unused block to hold the index of
	    		// the next unused block (single linked list melted inside the
	    		// data).
	    		unsigned char* p = data_;
	    		for (unsigned char i = 0; i != blocks; p += blockSize) {
	    			*p = ++i;
	    		}
	    	} // init

	    	// Release the allocated memory of a chunk.
	    	void release() {
	    		blocksAvailable_ = 0;
	    		delete[](data_);
	    	} // release

	    	// Allocate memory for a block inside chunk.
	    	// (Time complexity - linear)
	    	void* alloc(std::size_t blockSize) {
	    		assert(blockSize > 0;)
	    		// Implementation idea: fetch the block indexed 
	    		// by firstAvailableBlock_ and adjust firstAvailableBlock_ 
	    		// to refer to the next available block.
	    		if (!blocksAvailable_) {
	    			return 0;
	    		}
	    		unsigned char* result = 
	    			data_ + (firstAvailableBlock_ * blockSize);
	    		firstAvailableBlock_ = *result;
	    		--blocksAvailable;
	    		return result;
	    	} // alloc

	    	// Release memory of a block insied chunk.
	    	// If the wrong pointer is passed - behaviour is undefined.
	    	// (Time complexity - linear).
	    	void dealloc(void* block, std::size blockSize) {
	    		assert(blockSize > 0);
	    		assert(block >= data_);

	    		unsigned char* toRelease = static_cast<unsigned char*>(block);

	    		// Alignment check.
	    		assert(((toRelease - data_) % blockSize) == 0);

	    		// toRelease points to a block now which is considered 
	    		// available, so the first byte of the block pointed by
	    		// toRelease must hold indexed of next available  block,
	    		// which is still firstAvailableBlock_.
	    		*toRelease = firstAvailableBlock_;

	    		firstAvailableBlock_ = 
	    			static_cast<unsigned char>(toRelease - data_) / blockSize;

	    		// Truncation check.
	    		assert(firstAvailableBlock_ ==
	    			((toRelease - data_) / blockSize));

	    		++blocksAvailable_;
	    	} // dealloc

	    	unsigned char* data_;
	    	unsigned char firstAvailableBlock_,
	    		blocksAvailable_;
    	}; // struct Chunk

    private:
    	std::size_t blockSize_;
    	unsigned char numBlocks_;
    	typedef std::vector<Chunk> Chunks;
    	// FixedAllocator aggregates a vector of chunks.
    	Chunks chunks_;
    	// Pointer to the last chunk that was used for allocation.
    	Chunk* allocChunk_;
    	// Pointer to the last chunk used for deallocation.
    	Chunk* deallocChunk_;
    }; // class FixedAllocator


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
