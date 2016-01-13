#include "TableEditorController.h"
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

void TableEditorController::showCategoryAddingView(Utils::Observer* p_observer)
{
    AddCategoryView* addCategoryView = new AddCategoryView(m_appContext, m_mainWindow);
    addCategoryView->attach(p_observer);
    showWidgetWithFocus(addCategoryView);
}

void TableEditorController::showCategoryEditingView(Utils::Observer* p_observer)
{
    EditCategoryView* editCategoryView = new EditCategoryView(m_appContext, m_mainWindow);
    editCategoryView->attach(p_observer);
    showWidgetWithFocus(editCategoryView);
}
