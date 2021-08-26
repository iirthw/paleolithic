#pragma once

#include <memory>

/*
	TODO:
	* Make default pool size 1000;
*/

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
		// ctor, dtor
		
		ObjectPool(std::size_t capacity = min_capacity) {
			const auto buffer = 
				capacity > min_capacity ? capacity : min_capacity;
			mBuffer = std::make_shared<std::vector<T>>(capacity);
		}

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
		char mAvailabilityMask[maskSizeBytes];
		short mInUseCounter;

		static constexpr size_t min_capacity = 10;
		static constexpr size_t maskSizeBytes = 2;
	}; // class ObjectPool
} // namespace memory