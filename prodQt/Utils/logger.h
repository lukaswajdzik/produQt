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
        QString logFileName;
        QString getLogFileName(QFile&);
        QString determineFileName(QFile&);
        void establishLogFile(QString logFileName);
    };

}


#endif
