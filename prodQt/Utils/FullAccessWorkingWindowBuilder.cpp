#include "FullAccessWorkingWindowBuilder.h"
#include "Application/ApplicationContext.h"
#include "View/TableEditorView.h"
#include "View/WeightTabView.h"
#include "Utils/constants.h"

namespace Utils{

FullAccessWorkingWindowBuilder::FullAccessWorkingWindowBuilder(std::shared_ptr<Application::ApplicationContext> p_appContext) :
    m_appContext(std::move(p_appContext)),
    m_workingWindow(nullptr)
{
}

void FullAccessWorkingWindowBuilder::buildWeightTabView(MainWindowView* p_parent)
{
    buildWorkingWindow(p_parent);
    m_workingWindow->addTab(new WeightTabView(m_appContext, p_parent), Const::GetWeightTabViewName());
}

void FullAccessWorkingWindowBuilder::buildTableEditorView(MainWindowView* p_parent)
{
    buildWorkingWindow(p_parent);
    m_workingWindow->addTab(new TableEditorView(Const::GetProductTableDbName(), p_parent), Const::GetProductTableTabViewName());
}

WorkingTabsView* FullAccessWorkingWindowBuilder::getWorkingWindow()
{
    return m_workingWindow;
}

void FullAccessWorkingWindowBuilder::buildWorkingWindow(MainWindowView* p_parent)
{
    if(m_workingWindow)
        return;

    m_workingWindow = new WorkingTabsView(m_appContext, p_parent);
}

}

