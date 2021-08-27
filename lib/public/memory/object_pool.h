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
