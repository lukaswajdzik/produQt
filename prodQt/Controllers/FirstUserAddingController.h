#ifndef FADDUSER_H
#define FADDUSER_H

#include <memory>
#include <functional>
#include "IUserAddingController.h"

namespace Application{
    class ApplicationContext;
}

class FirstUserAddingController : public IUserAddingController
{
public:
    explicit FirstUserAddingController(std::shared_ptr<Application::ApplicationContext>);
    ~FirstUserAddingController() = default;
    void setCloseAction(std::function<void(void)>) override;
    void process() override;

private:
    std::shared_ptr<Application::ApplicationContext> m_appContext;
    std::function<void(void)> m_closeAction;
};

#endif // FADDUSER_H
