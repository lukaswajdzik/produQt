#ifndef LOGIN_H
#define LOGIN_H

namespace User {

    enum class Permission{
        none,
        superUser,
        admin,
        limited
    };

class Login
{
public:
    Login();
    ~Login();
    void changeAccess(const Permission);
    Permission getAccess();
private:
    Permission access;
};

}
#endif // LOGIN_H
