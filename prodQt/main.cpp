#include "Visuals/mainwindow.h"
#include <QApplication>
#include "Utils/logger.h"

using Logger = Utils::Logger;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Logger& logger = Logger::getInstance();
    logger.log("halo!");

    return a.exec();
}
