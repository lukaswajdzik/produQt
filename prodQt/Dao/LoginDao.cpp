#include "LoginDao.h"
#include "Database/databasequeryprovider.h"
#include "Utils/blowfishprovider.h"
#include "Dao/Exceptions/DbQueryCouldNotBeExecuted.h"
#include <QSqlQuery>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDebug>

namespace Dao {

    LoginDao::LoginDao(std::shared_ptr<QSqlQuery> p_connector) :
        m_connector(std::move(p_connector))
    {
    }

    LoginDao::~LoginDao()
    {
    }

    bool LoginDao::verifyUser(QString login, QString password) {
        QString userPassword = selectPasswordByUserName(login);
        QString userPasswordDecoded = Utils::BlowFishProvider::GetUserPasswordDecoded(userPassword);
        return password == userPasswordDecoded;
    }

    void LoginDao::copyUserData(UserDaoRecord &userData)
    {
        userData.userId = m_connector->value(0).toInt();
        userData.name = m_connector->value(1).toString();
        userData.role = m_connector->value(2).toInt();
    }

    UserDaoRecord LoginDao::getUserRecord(QString userName)
    {
        m_connector->prepare(Database::DatabaseQueryProvider::getUserData());
        m_connector->bindValue(0, userName);
        if(not m_connector->exec())
            throw new DbQueryCouldNotBeExecuted(m_connector->lastError());
        m_connector->next();
        UserDaoRecord userData;
        copyUserData(userData);
        return userData;
    }

    QString LoginDao::getUserDatabaseName()
    {
        return Database::DatabaseQueryProvider::getUserDatabaseName();
    }

    QString LoginDao::selectPasswordByUserName(QString userName) {
        m_connector->prepare(Database::DatabaseQueryProvider::getUserPassword() );
        m_connector->bindValue(0, userName);
        if(not m_connector->exec())
            throw new DbQueryCouldNotBeExecuted(m_connector->lastError());

        m_connector->next();
        return m_connector->value(0).toString();
    }

}

