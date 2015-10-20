#include "MainWindowController.h"
#include "View/LoginView.h"
#include "View/workingwindow.h"

MainWindowController::MainWindowController(std::shared_ptr<Application::ApplicationContext> p_appContext) :
    m_appContext(std::move(p_appContext))
{
}

MainWindowController::~MainWindowController()
{
}

LoginView *MainWindowController::getLoginWindow(MainWindowView *p_mainWindowPtr)
{
    return new LoginView(m_appContext, p_mainWindowPtr);
}

QWidget *MainWindowController::getView(IWorkingWindow & p_window)
{
    return p_window.getView();
}
