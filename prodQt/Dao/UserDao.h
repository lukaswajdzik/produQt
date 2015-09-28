#ifndef USERDAO_H
#define USERDAO_H
#include <memory>
#include <string>
#include <QString>


class QSqlQuery;


namespace Dao{

    struct UserAccountRecord{
        QString name;
        QString hash_pass;
        int role;
    };

    class UserDao
    {
    public:
        UserDao(std::shared_ptr<QSqlQuery>);
        ~UserDao();

        bool addUserToDatabase(UserAccountRecord);
        bool checkIfUserExist(QString);
    private:
        std::shared_ptr<QSqlQuery> m_connector;
    };

}

#endif // USERDAO_H
