#include "WorkingTabsView.h"
#include "Application/ApplicationContext.h"
#include "MainWindowView.h"
#include <QTabWidget>

WorkingTabsView::WorkingTabsView(std::shared_ptr<Application::ApplicationContext> p_appContext, MainWindowView *p_mainWindow) :
     QWidget(p_mainWindow),
     m_mainWindow(p_mainWindow),
     m_appContext(p_appContext)
{
    m_tabWidget = new QTabWidget(this);

    m_tabWidget->setStyleSheet("QTabBar::tab { height: 45px; width: 100px; }");
    m_tabWidget->setFixedSize(900,680);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    m_tabWidget->setFont(font);
    m_tabWidget->setAutoFillBackground(false);
    m_tabWidget->setObjectName(QStringLiteral("tabWidget"));
}

WorkingTabsView::~WorkingTabsView()
{
}

void WorkingTabsView::addTab(QWidget* p_tab, QString p_name)
{
    m_tabWidget->addTab(p_tab, p_name);
}

QWidget *WorkingTabsView::getView()
{
    return m_tabWidget;
}
