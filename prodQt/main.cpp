#include "Visuals/mainwindow.h"
#include "Visuals/databasetestwindow.h"
#include <QApplication>
#include "Utils/logger.h"

using Logger = Utils::Logger;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DataBaseTestWindow dtw;
    dtw.show();

    Logger& logger = Logger::getInstance();

    return a.exec();
}
