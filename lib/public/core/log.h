#include <ostream>

namespace core
{
    class Logger;
    extern Logger log;

    enum class LogLevel : unsigned char
    {
        INFO = 0,
        DEBUG,
        ERROR 
    }; // enum LogLevel

    class Logger
    {
    public:
        static Logger& getInstance();

        Logger(std::ostream& os = std::cout);

        Logger(const Logger&)           = delete;
        void operator= (const Logger&)  = delete;    
    }; // class Logger
} // namespace core