#include <QApplication>

#include "Utils/logger.h"
#include "Application/ApplicationContext.h"

using Logger = Utils::Logger;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Logger::getInstance().log("Application launched!");

    MainWindow window;
    Application::ApplicationContext context(window);

//    window.show();
    return a.exec();
}
