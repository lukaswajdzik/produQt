#include "LoginController.h"
#include "Modules/UserLoginModule.h"


LoginController::LoginController(std::shared_ptr<Application::ApplicationContext> p_appContext) :
    m_appContext(std::move(p_appContext))
{
    m_module = std::make_shared<Module::UserLoginModule>(m_appContext);
}

LoginController::~LoginController()
{
}

QSqlTableModel *LoginController::getUsersListModel(QWidget *parent)
{
    return m_module->getUserListModel(parent);
}

bool LoginController::logUser(QString p_name, QString p_pass)
{
    return m_module->logUser(p_name, p_pass);
}
