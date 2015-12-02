#ifndef USERDAO_H
#define USERDAO_H
#include <memory>
#include <string>
#include <QString>
#include "Dao/UserDaoRecord.h"

class QSqlQuery;

namespace Dao{

    class UserDao
    {
    public:
        UserDao(std::shared_ptr<QSqlQuery>);
        ~UserDao();

        bool addUserToDatabase(UserDaoRecord);
        bool checkIfUserExist(QString);
    private:
        std::shared_ptr<QSqlQuery> m_connector;
    };

}

#endif // USERDAO_H
