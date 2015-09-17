#ifndef USERMODIFIERCONTROLLER_H
#define USERMODIFIERCONTROLLER_H

#include <memory>

namespace Application
{
class ApplicationContext;
}

namespace Controller
{
using Application::ApplicationContext;

class UserModifierController
{
public:
    UserModifierController(ApplicationContext&);
    ~UserModifierController();
    void addUser();
    void modifyUser();
    void removeUser();
private:
    ApplicationContext& m_context;

};

}

#endif // USERMODIFIERCONTROLLER_H
