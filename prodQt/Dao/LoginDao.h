#ifndef LOGINDAO_H
#define LOGINDAO_H
#include <memory>
#include <QString>

class QSqlQuery;

namespace Dao {

    class LoginDao
    {
    public:
        LoginDao(std::shared_ptr<QSqlQuery>);
        ~LoginDao();

        bool verifyUser(QString, QString);
        QString getUserDatabaseName();

    private:
        std::shared_ptr<QSqlQuery> m_connector;

        QString selectPasswordByUserName(QString);
    };

}

#endif // LOGINDAO_H
