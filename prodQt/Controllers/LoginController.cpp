#include "LoginController.h"


LoginController::LoginController(std::shared_ptr<Application::ApplicationContext> p_appContext) :
    m_appContext(std::move(p_appContext))
{
}

LoginController::~LoginController()
{

}



