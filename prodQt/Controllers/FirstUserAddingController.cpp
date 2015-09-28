#include "FirstUserAddingController.h"
#include "Utils/constants.h"
#include "Modules/UserAddingModule.h"
#include "Application/ApplicationContext.h"
#include <QDebug>

FirstUserAddingController::FirstUserAddingController(std::shared_ptr<Application::ApplicationContext> p_context) :
    m_appContext(std::move(p_context))
{
}

void FirstUserAddingController::setCloseAction(std::function<void(void)> p_fcn)
{
}

void FirstUserAddingController::process()
{
    Module::UserAddingModule userAddingModule(m_appContext);
    userAddingModule.addUser("Administrator", "12345", 0);
}
