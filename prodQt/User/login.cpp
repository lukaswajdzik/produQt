#include "login.h"

namespace User{

Login::Login() : access(Permission::none)
{}

Login::~Login()
{}

void Login::changeAccess(Permission const perm)
{
    access = perm;
}

Permission Login::getAccess()
{
    return access;
}

}
