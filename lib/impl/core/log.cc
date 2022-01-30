#include "core/log.h"

namespace core
{
    Logger& getInstance()
    {
        static Logger instance;
        return instance;
    }
} // namespace core