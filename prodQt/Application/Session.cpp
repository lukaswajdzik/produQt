#include "Session.h"

namespace Application
{

    Session::Session()
    {
        m_accessType = 0;
    }

    Session::~Session()
    {

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
