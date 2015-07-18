#include "logger.h"
#include <QDateTime>
#include <QSettings>
#include <QApplication>
#include <QDebug>

namespace Utils
{

    Logger::Logger()
    {
        executeInitOperations();
    }

    void Logger::executeInitOperations(void)
    {
        settingFile = QApplication::applicationDirPath() + "/config.ini";
        qDebug() << "Config file path is: " << settingFile;
        establishLogFile(getLogFileName(settingFile));
        log("*Program starts");
    }

    Logger::~Logger()
    {
        log("*Program terminated");
        logFile.close();
    }

    Logger& Logger::getInstance()
    {
        static Logger instance;
        return instance;
    }

    void Logger::log(QString message)
    {
        QTextStream stream( &logFile );
        QDateTime time = QDateTime::currentDateTime();
        stream << time.toString("yyyy.MM.dd hh:mm:ss.z \t") << message << endl;
    }

    QString Logger::getLogFileName(QString settingFile)
    {
        QSettings settings(settingFile, QSettings::NativeFormat);
        QString logFileName = settings.value("logger/log_file", "logger.log").toString();
        qDebug() << "Logger file name is: " << logFileName;
        return logFileName;
    }

    void Logger::establishLogFile(QString logFileName)
    {
        logFile.setFileName(logFileName);
        logFile.open(QIODevice::Append | QIODevice::Text);
    }

}
