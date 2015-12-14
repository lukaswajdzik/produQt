#include "TableEditorController.h"
#include "View/CategoryEditorView.h"
#include "View/AddCategoryView.h"
#include "View/MainWindowView.h"
#include "View/EditCategoryView.h"

TableEditorController::TableEditorController(std::shared_ptr<Application::ApplicationContext> p_appContext,
                                             MainWindowView* p_mainWindow) :
    m_appContext(std::move(p_appContext)),
    m_mainWindow(p_mainWindow)
{

}

TableEditorController::~TableEditorController()
{

}

void TableEditorController::showWidgetWithFocus(QWidget* categoryView)
{
    categoryView->show();
    categoryView->activateWindow();
    categoryView->raise();
    categoryView->setFocus();
}

void TableEditorController::showCategoryAddingView()
{
    showWidgetWithFocus(new AddCategoryView(m_mainWindow));
}

void TableEditorController::showCategoryEditingView()
{
    showWidgetWithFocus(new EditCategoryView(m_mainWindow));
}
