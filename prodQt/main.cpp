#include <QApplication>
#include <memory>

#include "Utils/logger.h"
#include "Application/ApplicationContext.h"
#include "View/MainWindowView.h"

using Logger = Utils::Logger;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Logger::getInstance().log("Application launched!");

    auto context = std::make_shared<Application::ApplicationContext>();
    MainWindowView windowController(context);

    windowController.show();
    return a.exec();
}
