#include "logger.h"
#include <QDateTime>
#include <QSettings>
#include <QApplication>
#include <QDebug>

namespace Utils
{

    Logger::Logger()
    {
        settingFile = QApplication::applicationDirPath() + "/config.ini";
        qDebug() << "Config file path is: " << settingFile;
        establishLogFile(getLogFileName(settingFile));
        log("___Program starts___");
    }
    Logger::~Logger()
    {
        log("___Program terminated___");
        logFile.close();
    }

    void Logger::log(QString message)
    {
        QTextStream stream( &logFile );
        QDateTime time = QDateTime::currentDateTime();
        stream << time.toString("yyyy.MM.dd hh:mm:ss.z") << " - " << message << endl;
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
