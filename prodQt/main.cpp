#include <QApplication>

//#include "Visuals/mainwindow.h"
//#include "Visuals/databasetestwindow.h"
#include "Utils/logger.h"
#include "Control/processcontrol.h"

using Logger = Utils::Logger;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Logger::getInstance();

    Control::ProcessControl run;
    run.initOperations();

    return a.exec();
}
