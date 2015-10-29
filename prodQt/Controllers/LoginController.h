#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H
#include <memory>
#include <QStringList>

class QSqlTableModel;
class QWidget;

namespace Application{
    class ApplicationContext;
}
namespace Module {
    class UserLoginModule;
}

class LoginController
{
public:
    LoginController(std::shared_ptr<Application::ApplicationContext>);
    ~LoginController();

    QSqlTableModel *getUsersListModel(QWidget*);
    bool logUser(QString, QString);
    void setIsLogged();

private:
    std::shared_ptr<Application::ApplicationContext> m_appContext;
    std::shared_ptr<Module::UserLoginModule> m_module;

};

#endif // LOGINCONTROLLER_H
