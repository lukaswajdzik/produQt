#ifndef SESSION_H
#define SESSION_H

#include "Utils/Subject.h"
#include <QString>

namespace Application
{
    class Session : public Utils::Subject
    {
    public:
        Session();
        ~Session();
        bool isLogged();
        void logUser(QString, int);
        void logOut();

        bool getAccessType();
        void setAccessType(int);

    private:
        QString m_loggedUserName;
        bool m_isLogged;
        int m_accessType;
    };

}

#endif // SESSION_H
