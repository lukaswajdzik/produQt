#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <QString>
#include <memory>

namespace Database{
    class IOperativeDatabaseConnector;
}

namespace User{

struct UserData{
    QString name;
    int role;
    QString password;
};

class UserModifier
{
public:
    UserModifier(std::shared_ptr<Database::IOperativeDatabaseConnector>&);
    ~UserModifier();
    void addUser(UserData);
    void removeUser(QString);
    void editUser(UserData);
private:
    std::shared_ptr<Database::IOperativeDatabaseConnector> m_userOperativeDB;
};

}
#endif // USERACCOUNT_H
