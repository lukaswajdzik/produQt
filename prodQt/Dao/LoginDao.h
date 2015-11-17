#ifndef LOGINDAO_H
#define LOGINDAO_H
#include <memory>
#include <QString>

class QSqlQuery;

struct UserDao
{
    int userId;
    QString name;
    QString password;
    int role;
};

namespace Dao {

    class LoginDao
    {
    public:
        LoginDao(std::shared_ptr<QSqlQuery>);
        ~LoginDao();

        bool verifyUser(QString, QString);
        UserDao getUserRecord(QString);
        QString getUserDatabaseName();

    private:
        std::shared_ptr<QSqlQuery> m_connector;
        QString selectPasswordByUserName(QString);
    };

}

#endif // LOGINDAO_H
