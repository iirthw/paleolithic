#pragma once

namespace memory 
{
	template <typename T>
	class ObjectPool
	{
	public:

		ObjectPool(std::size_t capacity) : mCapacity(capacity) {}
		
	private:

		std::size_t mCapacity;
	}; // class ObjectPool
} // namespace memory