#ifndef MAINWINDOWCONRROLLER_H
#define MAINWINDOWCONRROLLER_H

#include <memory>
#include "Application/UserAccessType.h"

class QWidget;
class IWorkingWindow;
class MainWindowView;
class LoginView;
class WorkingTabsView;

namespace Application{
    class ApplicationContext;
}

namespace Utils{
    class WorkingWindowBuilder;
}

class MainWindowController
{
public:
    using UserAccessType = Application::UserAccessType;
    MainWindowController(std::shared_ptr<Application::ApplicationContext>);
    ~MainWindowController();

    IWorkingWindow *getLoginWindow(MainWindowView*);
    IWorkingWindow *getWorkingView(MainWindowView*);
    QWidget* getView(IWorkingWindow&);
    void logout();


private:
    std::shared_ptr<Utils::WorkingWindowBuilder> createViewBuilder(UserAccessType);
    std::shared_ptr<Application::ApplicationContext> m_appContext;
};

#endif // MAINWINDOWCONRROLLER_H
