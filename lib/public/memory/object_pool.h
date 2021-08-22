#pragma once

namespace memory 
{
	template <typename T>
	class ObjectPool
	{
	public:

		ObjectPool(std::size_t maxCapacity) : mMaxCapacity(maxCapacity) {}
		
	private:

		std::size_t mMaxCapacity;
	}; // class ObjectPool
} // namespace memory