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

