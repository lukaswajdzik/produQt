#include "LoginView.h"
#include "Controllers/LoginController.h"
#include "Utils/constants.h"
#include "MainWindowView.h"
#include "View/NumericKeyboard.h"
#include <QVBoxLayout>
#include <QTabWidget>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QLineEdit>
#include <QApplication>
#include <QDebug>
#include <QPushButton>
#include <QSqlTableModel>

LoginView::LoginView(std::shared_ptr<Application::ApplicationContext> p_appContext, MainWindowView *p_mainWindow)
    : QWidget(p_mainWindow),
      m_mainWindow(p_mainWindow)
{
    createNewObjects(p_mainWindow);

    setupTabWidget();
    setupLoginPushbutton();
    setupWidgets();
    setupLayout();
    setupObjectNames();
    setupPasswordLine();

    m_controller = std::make_shared<LoginController>(std::move(p_appContext));
    setupUserListInComboBox();
}

LoginView::~LoginView()
{
}

void LoginView::setupPasswordLine()
{
    m_lineEditUserPassword->setPlaceholderText("Hasło");
    m_lineEditUserPassword->setEchoMode(QLineEdit::Password);
    m_lineEditUserPassword->setAlignment(Qt::AlignCenter);
    m_lineEditUserPassword->setMaxLength(Utils::Constants::GetLenghtOfUserPassword());
}

void LoginView::setupObjectNames()
{
    m_tab->setObjectName(QStringLiteral("login"));
    m_comboBoxUserSelection->setObjectName(QStringLiteral("comboBoxUserSelection"));
    m_lineEditUserPassword->setObjectName(QStringLiteral("lineEditUserPassword"));
    m_tabLogin->setObjectName(QStringLiteral("tabLogin"));
    m_pbLogin->setObjectName(QStringLiteral("pbLogin"));
    m_verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
    m_layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
}

void LoginView::setupUserListInComboBox()
{
    m_userListModel = m_controller->getUsersListModel(m_tabLogin);
    m_comboBoxUserSelection->setModel(m_userListModel);
    m_comboBoxUserSelection->setModelColumn(1);
}

void LoginView::createNewObjects(QWidget *parent)
{
    m_tabLogin = new QTabWidget(parent);
    m_tab = new QWidget(m_tabLogin);
    m_pbLogin = new QPushButton("Zaloguj", m_tab);
    m_layoutWidget = new QWidget(m_tab);
    m_keyboardWidget = new QWidget(m_tab);
    m_verticalLayout = new QVBoxLayout(m_layoutWidget);
    m_keyboardLayout = new QHBoxLayout(m_keyboardWidget);
    m_comboBoxUserSelection = new QComboBox(m_layoutWidget);
    m_lineEditUserPassword = new QLineEdit(m_layoutWidget);
    m_keyboard = std::make_shared<NumericKeyboard>(nullptr, m_lineEditUserPassword);
}

void LoginView::setupTabWidget()
{
    m_tabLogin->setFixedSize(550,550);
    QFont font;
    font.setBold(true);
    font.setWeight(75);
    m_tabLogin->setFont(font);
    m_tabLogin->setAutoFillBackground(false);
    m_tabLogin->addTab(m_tab, QString());
    m_tabLogin->setTabText(m_tabLogin->indexOf(m_tab), QApplication::translate("MainWindow", "Logowanie", 0));
}

void LoginView::setupLoginPushbutton()
{
    m_pbLogin->setGeometry(QRect(300, 131, 151, 61));
    connect(m_pbLogin, SIGNAL(clicked()), this, SLOT(on_pbLogin_clicked()));
}

void LoginView::setupLayout()
{
    m_verticalLayout->setSpacing(6);
    m_verticalLayout->setContentsMargins(0, 0, 0, 0);
    m_verticalLayout->addWidget(m_comboBoxUserSelection);
    m_verticalLayout->addWidget(m_lineEditUserPassword);
    m_keyboardLayout->addWidget(m_keyboard->getView());
}

void LoginView::setupWidgets()
{
    m_layoutWidget->setGeometry(QRect(100, 130, 180, 65));
    m_keyboardWidget->setGeometry(QRect(0, 220, 550, 300));
}

QWidget *LoginView::getView()
{
    return m_tabLogin;
}

void LoginView::on_pbLogin_clicked()
{
    auto userName = m_comboBoxUserSelection->currentText();
    auto password = m_lineEditUserPassword->text();

    if(m_controller->logUser(userName, password))
    {
        m_mainWindow->setUserInfoText("Zalogowano użytkownka " + userName, "blue");
        m_controller->setIsLogged();
    }
    else
        m_mainWindow->setUserInfoText("Niepoprawne hasło dla użytkownika " + userName, "red");
}

