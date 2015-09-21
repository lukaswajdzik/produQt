#include "UserAddingControllerFactory.h"
#include "UserAddingController.h"
#include "FirstUserAddingController.h"

UserAddingControllerFactory::UserAddingControllerFactory(QWidget *p_widget, std::shared_ptr<Application::ApplicationContext> p_context) :
    m_parent(p_widget),
    m_context(p_context)
{}

UserAddingControllerFactory::~UserAddingControllerFactory()
{   
}

std::shared_ptr<IUserAddingController> UserAddingControllerFactory::create(bool firstUser)
{
    if(not firstUser)
    {
        return std::make_shared<UserAddingController>(m_parent, m_context);
    }
    return std::make_shared<FirstUserAddingController>(m_parent, m_context);
}

