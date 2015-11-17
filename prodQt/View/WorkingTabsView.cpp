#include "WorkingTabsView.h"
#include "Application/ApplicationContext.h"
#include "MainWindowView.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTabWidget>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QApplication>
#include <QDebug>
#include <QPushButton>


WorkingTabsView::WorkingTabsView(std::shared_ptr<Application::ApplicationContext> p_appContext, MainWindowView *p_mainWindow) :
     QWidget(p_mainWindow),
     m_mainWindow(p_mainWindow),
     m_appContext(p_appContext)
{
    m_tabWidget = new QTabWidget(this);
    m_layoutWidget = new QWidget(m_tabWidget);

    m_tabWidget->setFixedSize(900,690);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    m_tabWidget->setFont(font);
    m_tabWidget->setAutoFillBackground(false);
//    addTab();

//    m_layoutWidget->setGeometry(QRect(20, 20, 580, 365));

    m_tabWidget->setObjectName(QStringLiteral("tabLogin"));
    m_layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
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

void WorkingTabsView::on_pbLogin_clicked()
{
}

