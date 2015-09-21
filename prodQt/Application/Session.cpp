#include "Session.h"

namespace Application
{

    Session::Session() :
        m_isLogged(false),
        m_accessType(0)
    {}

    Session::~Session()
    {

    }

    bool Session::getIsLogged()
    {
        return m_isLogged;
    }

    void Session::setIsLogged(bool log)
    {
        m_isLogged = log;
    }

    bool Session::getAccessType()
    {
        return m_accessType;
    }

    void Session::setAccessType(int p_access)
    {
        m_accessType = p_access;
    }

}