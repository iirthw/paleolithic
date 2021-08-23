#pragma once

namespace memory 
{
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
		// ctors
		ObejctPool() : mCapacity(min_capacity) {}
		ObjectPool(std::size_t capacity) 
		: mCapacity(capacity > min_capacity ? capacity : min_capacity) {}

		// ---------------------------------------------------------------------
		// public interface
		size_t capacity() const { return mCapacity; }
		
	private:

		std::size_t mCapacity;

		static size_t min_capacity = 1000;
	}; // class ObjectPool
} // namespace memory