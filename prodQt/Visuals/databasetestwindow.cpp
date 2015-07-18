#include "databasetestwindow.h"
#include "ui_databasetestwindow.h"
#include "Utils/blowfishprovider.h"
#include <memory>

#include <exception>
#include <QDebug>
#include <QMessageBox>

using DatabaseConnector = Database::DatabaseConnector;
typedef unsigned char byte;

DataBaseTestWindow::DataBaseTestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataBaseTestWindow) {
    ui->setupUi(this);
    connect ( ui->loginButton, SIGNAL( clicked() ), this, SLOT( loginButtonClicked() ) );
}

DataBaseTestWindow::~DataBaseTestWindow() {
    delete ui;
}

void DataBaseTestWindow::loginButtonClicked() {
    try {
        DbCon = std::make_shared<DatabaseConnector>();
        QString userName = ui->userNameBox->toPlainText();
        QString userPassword = ui->userPasswordBox->toPlainText();
//        if(userName.isEmpty() || userPassword.isEmpty()) {
//            return;
//        }
        QString validation = DbCon-> VerifyUser(userName, userPassword) ? "Passed" : "Failed";
        ui->statusLabel->setText("Validation: " + validation);
        logger.log("Data base OK!");
    }
    catch(std::exception& e) {
        qDebug() << e.what();
        logger.log("Data base exception rised!");
        QMessageBox::information(0, "FAULT",  "Database connection could not be established.");
    }
}

void DataBaseTestWindow::on_loginButton_clicked(){

}
