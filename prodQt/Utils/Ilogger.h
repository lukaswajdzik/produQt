#ifndef ILOGGER_H
#define ILOGGER_H

#include <string>

namespace Utils
{

class ILogger
{
//wide accesible singleton
public:
    virtual void log(std::string message) = 0;
    virtual ~ILogger()
    {}
};

}//namespace Utils

#endif // ILOGGER_H
