#ifndef LOGINDAO_H
#define LOGINDAO_H
#include <memory>
#include <QString>
#include "Dao/UserDaoRecord.h"
class QSqlQuery;


namespace Dao {

    class LoginDao
    {
    public:
        LoginDao(std::shared_ptr<QSqlQuery>);
        ~LoginDao();

        bool verifyUser(QString, QString);
        UserDaoRecord getUserRecord(QString);
        QString getUserDatabaseName();

    private:
        void copyUserData(UserDaoRecord&);
        std::shared_ptr<QSqlQuery> m_connector;
        QString selectPasswordByUserName(QString);
    };

}

#endif // LOGINDAO_H
