#ifndef LOGGER_H
#define LOGGER_H

#include <QString>

namespace Utils
{

class Logger
{
public:
    static Logger& getInstance()
    {
        static Logger instance;
        return instance;
    }
    void log(QString message);

private:
    Logger()
    {}
    Logger(Logger const& copy)            = delete;
    Logger& operator=(Logger const& copy) = delete;
};

}//namespace Utils


#endif
