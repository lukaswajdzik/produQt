#ifndef LOGGER_H
#define LOGGER_H
#include "Ilogger.h"

namespace Utils
{
class Logger : public ILogger
{
public:
    Logger();
    void log(std::string message) override;
};

}//namespace Utils

#endif // LOGGER_H
