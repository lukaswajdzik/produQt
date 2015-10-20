#ifndef MAINWINDOWCONRROLLER_H
#define MAINWINDOWCONRROLLER_H

#include <memory>

class QWidget;
class IWorkingWindow;
class MainWindowView;
class LoginView;

namespace Application{
    class ApplicationContext;
}

class MainWindowController
{
public:
    MainWindowController(std::shared_ptr<Application::ApplicationContext>);
    ~MainWindowController();

    LoginView *getLoginWindow(MainWindowView*);
    QWidget* getView(IWorkingWindow&);


private:
    std::shared_ptr<Application::ApplicationContext> m_appContext;
};

#endif // MAINWINDOWCONRROLLER_H
