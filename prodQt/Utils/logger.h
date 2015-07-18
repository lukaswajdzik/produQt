#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QFile>

namespace Utils
{
    class Logger
    {
    public:
        static Logger& getInstance();
        void log(QString message);

    private:
        Logger();
        ~Logger();
        Logger(Logger const& copy)            = delete;
        Logger& operator=(Logger const& copy) = delete;
        void executeInitOperations();
        QFile logFile;
        QString settingFile;
        QString logFileName;
        QString getLogFileName(QString settingFile);
        void establishLogFile(QString logFileName);
    };
}


#endif
