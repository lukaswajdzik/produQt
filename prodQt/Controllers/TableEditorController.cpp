#include "TableEditorController.h"
#include "View/CategoryEditorView.h"

TableEditorController::TableEditorController(std::shared_ptr<Application::ApplicationContext> p_appContext,
                                             MainWindowView* p_mainWindow) :
    m_appContext(std::move(p_appContext)),
    m_mainWindow(p_mainWindow)
{

}

TableEditorController::~TableEditorController()
{

}

QWidget *TableEditorController::getCategoryView()
{
    auto categoryView = new CategoryEditorView("abc", m_mainWindow);
    return categoryView->getView();

}

