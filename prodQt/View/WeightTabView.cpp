#include "WeightTabView.h"
#include "View/MainWindowView.h"
#include "Application/ApplicationContext.h"
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>

WeightTabView::WeightTabView(std::shared_ptr<Application::ApplicationContext> p_appContext, MainWindowView *p_mainWindow) :
  QWidget(p_mainWindow),
  m_mainWindow(p_mainWindow),
  m_appContext(p_appContext)
{
    m_weightTab = new QWidget(this);
    m_pb = new QPushButton("Waga", m_weightTab);
    m_comboBoxUserSelection = new QComboBox(m_weightTab);
    m_lineEditUserPassword = new QLineEdit(m_weightTab);

    m_mainLayout = new QGridLayout(m_weightTab);
    m_leftSideLayout = new QVBoxLayout(m_weightTab);
    m_rightSideLayout = new QVBoxLayout(m_weightTab);
    m_mainLayout->addLayout(m_leftSideLayout, 0, 0);
    m_mainLayout->addLayout(m_rightSideLayout, 0, 2);

    m_mainLayout->setSpacing(6);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_leftSideLayout->addWidget(m_comboBoxUserSelection);
    m_leftSideLayout->addWidget(m_pb);
    m_rightSideLayout->addWidget(m_lineEditUserPassword);

    m_weightTab->setObjectName(QStringLiteral("login"));
    m_comboBoxUserSelection->setObjectName(QStringLiteral("comboBoxUserSelection"));
    m_lineEditUserPassword->setObjectName(QStringLiteral("lineEditUserPassword"));
    m_pb->setObjectName(QStringLiteral("pbLogin"));
    m_mainLayout->setObjectName(QStringLiteral("verticalLayout"));

    m_lineEditUserPassword->setPlaceholderText(QString::number(m_mainLayout->columnCount()));
//    connect(m_pb, SIGNAL(clicked()), this, SLOT(on_pbLogin_clicked()));
}

WeightTabView::~WeightTabView()
{

}

QWidget *WeightTabView::getView()
{
    return this;
}

