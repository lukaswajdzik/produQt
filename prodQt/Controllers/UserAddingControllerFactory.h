#ifndef USERADDINGCONTROLLERFACTORY_H
#define USERADDINGCONTROLLERFACTORY_H

#include "IUserAddingController.h"
#include <memory>

class QWidget;
namespace Application{
    class ApplicationContext;
}

class UserAddingControllerFactory
{
public:
    UserAddingControllerFactory(QWidget*, std::shared_ptr<Application::ApplicationContext>);
    ~UserAddingControllerFactory();

    std::shared_ptr<IUserAddingController> create(bool);

private:
    QWidget* m_parent;
    std::shared_ptr<Application::ApplicationContext> m_context;

};

#endif // USERADDINGCONTROLLERFACTORY_H
