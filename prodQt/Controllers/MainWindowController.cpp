#include "MainWindowController.h"
#include "View/LoginView.h"
#include "View/IWorkingWindow.h"
#include "View/WorkingTabsView.h"
#include "Application/ApplicationContext.h"
#include "View/NumericKeyboard.h"

#include "View/TableEditorView.h"
#include "View/WeightTabView.h"
#include "Utils/FullAccessWorkingWindowBuilder.h"

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
    auto viewBuilder = createViewBuilder(m_appContext->getSession().getAccessType());

    viewBuilder->buildWeightTabView(p_mainWindowPtr);
    viewBuilder->buildTableEditorView(p_mainWindowPtr);

    return viewBuilder->getWorkingWindow();
}

std::shared_ptr<Utils::WorkingWindowBuilder> MainWindowController::createViewBuilder(UserAccessType p_access)
{
    std::shared_ptr<Utils::WorkingWindowBuilder> viewBuilder;
    if(p_access == UserAccessType::FULL)
    {
        viewBuilder = std::make_shared<Utils::FullAccessWorkingWindowBuilder>(m_appContext);
    }
    else if(p_access == UserAccessType::LIMITED)
    {
        //viewBuilder = 'limited' Bulider
    }
    return viewBuilder;
}

QWidget *MainWindowController::getView(IWorkingWindow & p_window)
{
    return p_window.getView();
}

void MainWindowController::logout()
{
    m_appContext->getSession().logOut();
}
