#ifndef MAINWINDOWCONRROLLER_H
#define MAINWINDOWCONRROLLER_H

#include <memory>

class QWidget;
class IWorkingWindow;
class MainWindowView;
class LoginView;
class WorkingView;

namespace Application{
    class ApplicationContext;
}

class MainWindowController
{
public:
    MainWindowController(std::shared_ptr<Application::ApplicationContext>);
    ~MainWindowController();

    IWorkingWindow *getLoginWindow(MainWindowView*);
    IWorkingWindow *getWorkingView(MainWindowView*);
    QWidget* getView(IWorkingWindow&);
    void logout();


private:
    std::shared_ptr<Application::ApplicationContext> m_appContext;
};

#endif // MAINWINDOWCONRROLLER_H
