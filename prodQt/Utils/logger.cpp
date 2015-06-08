#include "logger.h"
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

namespace Utils
{

void Logger::log(QString message)
{
    QFile configFile("config");

    if(!configFile.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0, "ERROR",  "Can't fine 'config' file!"
                                              "\n(place it in the build directory)");
    }

    QTextStream in(&configFile);

    QString logFileName;
    while(!in.atEnd())
        logFileName = in.readLine();

    configFile.close();

    QFile logFile( logFileName );
    if ( logFile.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &logFile );
        stream << message << "\n" << endl;
    }

}

} //namespace Utils
