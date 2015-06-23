#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QFile>
#include <QTextStream>

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
        Logger();
        ~Logger();
        Logger(Logger const& copy)            = delete;
        Logger& operator=(Logger const& copy) = delete;
        QFile logFile;
        QString settingFile;
        QString logFileName;
        QString getLogFileName(QString settingFile);
        void establishLogFile(QString logFileName);
    };

}


#endif
