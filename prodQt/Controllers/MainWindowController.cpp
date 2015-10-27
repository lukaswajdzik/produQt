#include "MainWindowController.h"
#include "View/LoginView.h"
#include "View/IWorkingWindow.h"
#include "View/WorkingView.h"

MainWindowController::MainWindowController(std::shared_ptr<Application::ApplicationContext> p_appContext) :
    m_appContext(std::move(p_appContext))
{
}

MainWindowController::~MainWindowController()
{
}

IWorkingWindow *MainWindowController::getLoginWindow(MainWindowView *p_mainWindowPtr)
{
    return new LoginView(m_appContext, p_mainWindowPtr);
}

IWorkingWindow *MainWindowController::getWorkingView(MainWindowView *p_mainWindowPtr)
{
    return new WorkingView(m_appContext, p_mainWindowPtr);
}

QWidget *MainWindowController::getView(IWorkingWindow & p_window)
{
    return p_window.getView();
}
