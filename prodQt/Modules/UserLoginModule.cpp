#include "UserLoginModule.h"
#include "Dao/LoginDao.h"
#include "Utils/logger.h"
#include <QSqlTableModel>
#include <QDebug>

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

    bool UserLoginModule::verifyUser(QString p_name, QString p_pass)
    {
        auto result = false;
        try{
            result = m_loginDao->verifyUser(p_name, p_pass);
        }
        catch(std::exception* ex){
            Utils::Logger::getInstance().log(ex->what());
            qDebug() << ex->what();
            delete ex;
        }
        return result;

    }

    void UserLoginModule::logUser(QString p_name)
    {
        UserDao user;
        int a;
//        user = m_loginDao->getUserRecord(p_name);
//        m_appContext->getSession().logUser(user.name, user.role);
    }

    QSqlTableModel *UserLoginModule::getUserListModel(QWidget *parent)
    {
        QSqlTableModel *l_userListModel = new QSqlTableModel(parent);
        l_userListModel->setTable(m_loginDao->getUserDatabaseName());
        l_userListModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
        l_userListModel->select();
        return l_userListModel;
    }

}

