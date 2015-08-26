#include "operativedatabaseconnector.h"
#include "Database/databasequeryprovider.h"
#include "Utils/blowfishprovider.h"
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDebug>

namespace Database {

    OperativeDatabaseConnector::OperativeDatabaseConnector()
    {

    }

    OperativeDatabaseConnector::~OperativeDatabaseConnector()
    {

    }

    bool OperativeDatabaseConnector::VerifyUser(QString login, QString password) {
        QString userPassword = SelectPasswordByUserName(login);
        QString userPasswordDecoded = Utils::BlowFishProvider::GetUserPasswordDecoded(userPassword);
        return password == userPasswordDecoded;
    }

    QString OperativeDatabaseConnector::SelectPasswordByUserName(QString userName) {
        QSqlQuery query;
        query.prepare(DatabaseQueryProvider::getUserPassword() );
        query.bindValue(":userName", userName);
        query.exec();
        query.next();
        return query.value(0).toString();
    }

    void OperativeDatabaseConnector::addUserToDatabase(User::UserData p_userData)
    {
        QSqlQuery query;
        query.prepare(DatabaseQueryProvider::addUser() );
        query.bindValue(":userName", p_userData.name);
        query.bindValue(":userPass", p_userData.password);
        query.bindValue(":userRole", int(p_userData.role));
        qDebug() << "!Query: " << query.exec();
    }

}
