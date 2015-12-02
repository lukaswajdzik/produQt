#include "Session.h"

namespace Application
{
    Session::Session() :
        m_loggedUserName(""),
        m_isLogged(false),
        m_accessType(UserAccessType::NONE)
    {}

    Session::~Session()
    {
    }

    bool Session::isLogged()
    {
        return m_isLogged;
    }

    void Session::logUser(QString name, UserAccessType p_role)
    {
        m_isLogged = true;
        m_loggedUserName = name;
        m_accessType = p_role;
        notify();
    }

    void Session::logOut()
    {
        m_isLogged = false;
        m_loggedUserName.clear();
        m_accessType = UserAccessType::NONE;
        notify();
    }

    UserAccessType Session::getAccessType()
    {
        return m_accessType;
    }

}
