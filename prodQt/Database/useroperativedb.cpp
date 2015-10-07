#include "Database/useroperativedb.h"
#include "Database/databasequeryprovider.h"
#include "Utils/blowfishprovider.h"
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QMessageBox>

namespace Database {

    UserOperativeDb::UserOperativeDb()
    {}

    UserOperativeDb::~UserOperativeDb()
    {}

    bool UserOperativeDb::VerifyUser(QString login, QString password) {
        QString userPassword = SelectPasswordByUserName(login);
        QString userPasswordDecoded = Utils::BlowFishProvider::GetUserPasswordDecoded(userPassword);
    QMessageBox::information(0, "PASS",  userPasswordDecoded);
        return password == userPasswordDecoded;
    }

    QString UserOperativeDb::SelectPasswordByUserName(QString userName) {
        QSqlQuery query;
        query.prepare(DatabaseQueryProvider::getUserPassword() );
        query.bindValue(0, userName);
        query.exec();
        query.next();
        return query.value(0).toString();
    }
}
