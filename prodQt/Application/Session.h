#ifndef SESSION_H
#define SESSION_H

#include "Utils/Subject.h"

namespace Application
{
    class Session : public Utils::Subject
    {
    public:
        Session();
        ~Session();
        bool getIsLogged();
        void setIsLogged(bool);

        bool getAccessType();
        void setAccessType(int);

    private:
        bool m_isLogged;
        int m_accessType;
    };

}

#endif // SESSION_H
