#include <QApplication>
#include <memory>

#include "Utils/logger.h"
#include "Application/ApplicationContext.h"

using Logger = Utils::Logger;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Logger::getInstance().log("Application launched!");

    auto context = std::make_shared<Application::ApplicationContext>();
    MainWindowController windowController(context);

    windowController.show();
    return a.exec();
}
