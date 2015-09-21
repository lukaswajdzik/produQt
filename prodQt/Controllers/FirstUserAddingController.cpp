#include "FirstUserAddingController.h"
#include "ui_adduser.h"
#include "Utils/constants.h"
#include "Modules/UserAddingModule.h"
#include "Database/useroperativedb.h"
#include "Application/ApplicationContext.h"
#include <QDebug>

enum Access{
    Full, //0
    Limited //1
};

FirstUserAddingController::FirstUserAddingController(QWidget *parent, std::shared_ptr<Application::ApplicationContext> p_context) :
    QDialog(parent),
    m_appContext(std::move(p_context)),
    m_ui(new Ui::AddUser)
{
    qDebug() << "contructor of FirstUserAddingController";
    m_ui->setupUi(this);
    m_ui->comboBoxAccess->addItems(Utils::Constants::GetAccessTypes());
}

FirstUserAddingController::~FirstUserAddingController()
{
    qDebug() << "destructor of FirstUserAddingController";
    delete m_ui;
}

void FirstUserAddingController::setCloseAction(std::function<void(void)> p_fcn)
{
    m_closeAction = p_fcn;
}

void FirstUserAddingController::show()
{
    QDialog::show();
}

void FirstUserAddingController::on_pushButtonAddUser_clicked()
{
    std::shared_ptr<Database::IOperativeDatabaseConnector> userOperativeDB = std::make_shared<Database::UserOperativeDb>();
    Module::UserData userData;
    Module::UserAddingModule userAddingModule(m_appContext, userOperativeDB);

    userData.name = m_ui->lineEditUserName->text();
    userData.password = m_ui->lineEditPassword1->text();
    userData.role = (m_ui->comboBoxAccess->currentIndex());

    userAddingModule.addUser(userData);
}

void FirstUserAddingController::on_pushButtonReject_released()
{
    m_closeAction();
}
