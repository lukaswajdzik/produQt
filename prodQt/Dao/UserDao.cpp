#include "UserDao.h"
#include "Utils/logger.h"
#include "Database/databasequeryprovider.h"
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDebug>

namespace Dao {

    UserDao::UserDao(std::shared_ptr<QSqlQuery> p_connector) :
        m_connector(std::move(p_connector))
    {}

    UserDao::~UserDao()
    {
    }

    void UserDao::addUserToDatabase(UserAccountRecord p_userData) {
        m_connector->prepare(Database::DatabaseQueryProvider::addUser() );
        m_connector->bindValue(0, p_userData.name);
        m_connector->bindValue(1, p_userData.hash_pass);
        m_connector->bindValue(2, p_userData.role);
        if(not m_connector->exec())
        {
            Utils::Logger::getInstance().log("ERROR: Fail to add new user: " + p_userData.name + " to the DataBase!");
        }
    }

    bool UserDao::checkIfUserExist(QString p_userName)
    {
        m_connector->prepare(Database::DatabaseQueryProvider::existUser());
        m_connector->bindValue(0, p_userName);
        if(not m_connector->exec())
        {
            Utils::Logger::getInstance().log("ERROR: Fail to check if user exist");
        }
        m_connector->next();
        return m_connector->value(0).toBool();
    }
}

