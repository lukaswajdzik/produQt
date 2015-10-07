#ifndef USERLOGINMODULE_H
#define USERLOGINMODULE_H
#include <QString>
#include "Modules/Module.h"

namespace Application {
    class ApplicationContext;
}

namespace Dao{
    class LoginDao;
}

namespace Module{

    class UserLoginModule : public Module
    {
    public:
        UserLoginModule(std::shared_ptr<Application::ApplicationContext>);
        ~UserLoginModule();

        void logUser(QString, QString);

    private:
        std::shared_ptr<Application::ApplicationContext> m_appContext;
        std::shared_ptr<Dao::LoginDao> m_loginDao;
    };

}


#endif // USERLOGINMODULE_H
