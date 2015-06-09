#include "logger.h"
#include <iostream>
#include <QMessageBox>
#include <QDateTime>

namespace Utils
{

    Logger::Logger()
    {
        QFile configFile("config");
        logFileName = determineFileName(configFile);
        configFile.close();
        establishLogFile(logFileName);
        log("Logger is on!");
    }
    Logger::~Logger()
    {
        logFile.close();
    }

    void Logger::log(QString message)
    {
        QTextStream stream( &logFile );
        QDateTime time = QDateTime::currentDateTime();
        stream << time.toString("d MMM yyyy hh:mm:ss") << " - " << message << endl;
    }

    QString Logger::getLogFileName(QFile& file)
    {
        QTextStream in(&file);

        QString logFileName;
        logFileName = in.readLine();
        return logFileName;
    }

    QString Logger::determineFileName(QFile& file)
    {
        if(!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::information(0, "WARNING",  "Can't fine 'config' file!"
                                                  "\nFile with the logs will be created as 'Logs.txt'");
            return "Logs.txt";
        }
        else
        {
            return getLogFileName(file);
        }
    }

    void Logger::establishLogFile(QString logFileName)
    {
        logFile.setFileName(logFileName);
        logFile.open(QIODevice::ReadWrite | QIODevice::Text);
    }


}
