#ifndef FADDUSER_H
#define FADDUSER_H

#include <QDialog>
#include <memory>
#include <functional>
#include "IUserAddingController.h"

namespace Ui {
    class AddUser;
}

namespace Application{
    class ApplicationContext;
}

class FirstUserAddingController : public QDialog,
                                  public IUserAddingController
{
    Q_OBJECT

public:
    explicit FirstUserAddingController(QWidget *parent, std::shared_ptr<Application::ApplicationContext>);
    ~FirstUserAddingController();
    void setCloseAction(std::function<void(void)>) override;
    void show() override;

private slots:
    void on_pushButtonAddUser_clicked();
    void on_pushButtonReject_released();

private:
    std::shared_ptr<Application::ApplicationContext> m_appContext;
    Ui::AddUser *m_ui;
    std::function<void(void)> m_closeAction;
};

#endif // FADDUSER_H
