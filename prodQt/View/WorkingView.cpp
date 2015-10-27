#include "WorkingView.h"
#include "Application/ApplicationContext.h"
#include "MainWindowView.h"
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QApplication>
#include <QDebug>
#include <QPushButton>

WorkingView::WorkingView(std::shared_ptr<Application::ApplicationContext> p_appContext, MainWindowView *p_mainWindow) :
     QWidget(p_mainWindow),
     m_mainWindow(p_mainWindow),
     m_appContext(p_appContext)
{
    m_tabLogin = new QTabWidget(this);
    m_tab = new QWidget(m_tabLogin);
    m_pbLogin = new QPushButton("Nowy!", m_tab);
    m_layoutWidget = new QWidget(m_tab);
    m_verticalLayout = new QVBoxLayout(m_layoutWidget);
    m_comboBoxUserSelection = new QComboBox(m_layoutWidget);
    m_lineEditUserPassword = new QLineEdit(m_layoutWidget);

    m_tabLogin->setFixedSize(550,550);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    m_tabLogin->setFont(font);
    m_tabLogin->setAutoFillBackground(false);
    m_tabLogin->addTab(m_tab, QString());
    m_tabLogin->setTabText(m_tabLogin->indexOf(m_tab), QApplication::translate("MainWindow", "Działaj!", 0));

    m_layoutWidget->setGeometry(QRect(20, 20, 580, 365));

    m_verticalLayout->setSpacing(6);
    m_verticalLayout->setContentsMargins(0, 0, 0, 0);
    m_verticalLayout->addWidget(m_comboBoxUserSelection);
    m_verticalLayout->addWidget(m_lineEditUserPassword);

    m_tab->setObjectName(QStringLiteral("login"));
    m_comboBoxUserSelection->setObjectName(QStringLiteral("comboBoxUserSelection"));
    m_lineEditUserPassword->setObjectName(QStringLiteral("lineEditUserPassword"));
    m_tabLogin->setObjectName(QStringLiteral("tabLogin"));
    m_pbLogin->setObjectName(QStringLiteral("pbLogin"));
    m_verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    m_layoutWidget->setObjectName(QStringLiteral("layoutWidget"));

    m_lineEditUserPassword->setPlaceholderText("Nico");
    qDebug()<<"aaaa!";
}

WorkingView::~WorkingView()
{

}

QWidget *WorkingView::getView()
{
    return m_tabLogin;
}

