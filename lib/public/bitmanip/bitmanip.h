#pragma once

namespace bitmanip
{
    template <typename T>
    static bool is_power2(const T& x)
    {
        return x && !(x & (x - 1));
    }
} // namespace bitmanip