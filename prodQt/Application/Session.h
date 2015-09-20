#ifndef SESSION_H
#define SESSION_H

namespace Application
{
    class Session
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
