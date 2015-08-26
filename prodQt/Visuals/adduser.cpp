#include "adduser.h"
#include "ui_adduser.h"
#include "Utils/constants.h"
#include "Database/operativedatabaseconnector.h"

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
    Database::OperativeDatabaseConnector haha;
    haha.addUserToDatabase();

}
