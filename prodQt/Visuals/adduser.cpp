#include "adduser.h"
#include "ui_adduser.h"
#include "Utils/constants.h"
#include "User/usermodifier.h"
#include "Database/useroperativedb.h"
#include <memory>

enum Access{
    Full, //0
    Limited //1
};

AddUser::AddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);
    ui->comboBoxAccess->addItems(Utils::Constants::GetAccessTypes());
}

AddUser::~AddUser()
{
    delete ui;
}

void AddUser::on_pushButtonAddUser_clicked()
{
    std::shared_ptr<Database::IOperativeDatabaseConnector> userOperativeDB = std::make_shared<Database::UserOperativeDb>();
    User::UserData userData;
    User::UserModifier userModifier(userOperativeDB);

    userData.name = ui->lineEditUserName->text();
    userData.password = ui->lineEditPassword1->text();
    userData.role = (ui->comboBoxAccess->currentText() == Utils::Constants::GetAccessTypes().at(0) ? Access::Full : Access::Limited);

    userModifier.addUser(userData);
}
