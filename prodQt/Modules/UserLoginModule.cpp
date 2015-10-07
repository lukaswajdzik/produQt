#include "UserLoginModule.h"
#include "Dao/LoginDao.h"

namespace Module{

    UserLoginModule::UserLoginModule(std::shared_ptr<Application::ApplicationContext> p_appContext) :
        Module(p_appContext),
        m_appContext(std::move(p_appContext))
    {
        m_loginDao = std::make_shared<Dao::LoginDao>(m_appContext->getConnection());
    }

    UserLoginModule::~UserLoginModule()
    {
    }

    void UserLoginModule::logUser(QString p_name, QString p_pass)
    {
        m_loginDao->verifyUser(p_name, p_pass);
    }

}

