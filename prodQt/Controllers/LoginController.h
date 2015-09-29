#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include <memory>

namespace Application{
    class ApplicationContext;
}

class LoginController
{
public:
    LoginController(std::shared_ptr<Application::ApplicationContext>);
    ~LoginController();
private:
    std::shared_ptr<Application::ApplicationContext> m_appContext;
};

#endif // LOGINCONTROLLER_H
