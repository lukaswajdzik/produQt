#ifndef SESSION_H
#define SESSION_H

#include "Utils/Subject.h"
#include <QString>
#include "Application/UserAccessType.h"

namespace Application
{
    class Session : public Utils::Subject
    {
    public:
        Session();
        ~Session();
        bool isLogged();
        void logUser(QString, UserAccessType);
        void logOut();

        UserAccessType getAccessType();

    private:
        QString m_loggedUserName;
        bool m_isLogged;
        UserAccessType m_accessType;
    };

}

#endif // SESSION_H
