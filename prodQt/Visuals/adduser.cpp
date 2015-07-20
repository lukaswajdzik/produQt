#include "adduser.h"
#include "ui_adduser.h"

AddUser::AddUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUser)
{
    ui->setupUi(this);
    ui->comboBoxAccess->addItems({"Administrator", "Operator"});
}

AddUser::~AddUser()
{
    delete ui;
}
