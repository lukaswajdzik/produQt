#ifndef SESSION_H
#define SESSION_H

namespace Application
{

    class Session
    {
    private:
        int m_accessType;

    public:
        Session();
        ~Session();
        bool getAccessType();
        void setAccessType(int);
    };

}

#endif // SESSION_H
