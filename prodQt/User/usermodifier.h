#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <QString>

namespace User{

struct UserData{
    QString name;
    int role;
    QString password;
};

class UserModifier
{
public:
    UserModifier();
    ~UserModifier();
    void addUser(UserData);
    void removeUser(QString);
    void editUser(UserData);
private:
    
};

}
#endif // USERACCOUNT_H
