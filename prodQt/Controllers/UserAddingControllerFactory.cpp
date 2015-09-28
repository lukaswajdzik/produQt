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

std::shared_ptr<IUserAddingController> UserAddingControllerFactory::createConsecutiveUser(QSqlTableModel* p_userModel)
{
    return std::make_shared<UserAddingController>(m_parent, m_context, p_userModel);
}

std::shared_ptr<IUserAddingController> UserAddingControllerFactory::createFirstUser()
{
    return std::make_shared<FirstUserAddingController>(m_context);
}

