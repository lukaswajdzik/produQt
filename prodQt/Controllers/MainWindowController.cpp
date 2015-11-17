#include "MainWindowController.h"
#include "View/LoginView.h"
#include "View/IWorkingWindow.h"
#include "View/WorkingTabsView.h"
#include "Application/ApplicationContext.h"
#include "View/NumericKeyboard.h"

#include "View/TableEditorView.h"
#include "View/WeightTabView.h"

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
//    return new WorkingTabsView(m_appContext, p_mainWindowPtr);
    WorkingTabsView* abc = new WorkingTabsView(m_appContext, p_mainWindowPtr);
    TableEditorView* b = new TableEditorView("products", 0);
    WeightTabView* c = new WeightTabView(m_appContext, p_mainWindowPtr);
    abc->addTab(c, "aleaaaaa");
    return abc;
}
void addTabs(WorkingTabsView* tabs)
{
    TableEditorView * b = new TableEditorView("products", 0);
    tabs->addTab(b->getView(), "--Lista Produktów--");
}

QWidget *MainWindowController::getView(IWorkingWindow & p_window)
{
    return p_window.getView();
}

void MainWindowController::logout()
{
    m_appContext->getSession().logOut();
}
