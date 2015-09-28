#ifndef USERADDINGCONTROLLERFACTORY_H
#define USERADDINGCONTROLLERFACTORY_H

#include "IUserAddingController.h"
#include <memory>

class QWidget;
class QSqlTableModel;
namespace Application{
    class ApplicationContext;
}

class UserAddingControllerFactory
{
public:
    UserAddingControllerFactory(QWidget*, std::shared_ptr<Application::ApplicationContext>);
    ~UserAddingControllerFactory();

    std::shared_ptr<IUserAddingController> createFirstUser();
    std::shared_ptr<IUserAddingController> createConsecutiveUser(QSqlTableModel*);

private:
    QWidget* m_parent;
    std::shared_ptr<Application::ApplicationContext> m_context;

};

#endif // USERADDINGCONTROLLERFACTORY_H
