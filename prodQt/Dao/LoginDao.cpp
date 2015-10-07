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

    QString LoginDao::selectPasswordByUserName(QString userName) {
        QSqlQuery query;
        query.prepare(Database::DatabaseQueryProvider::getUserPassword() );
        query.bindValue(0, userName);
        if(not m_connector->exec())
            throw new DbQueryCouldNotBeExecuted(m_connector->lastError());

        query.next();
        return query.value(0).toString();
    }

}

