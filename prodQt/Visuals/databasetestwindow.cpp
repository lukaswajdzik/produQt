#include "databasetestwindow.h"
#include "ui_databasetestwindow.h"
#include "Database/databaseconnector.h"

#include <exception>
#include <QDebug>
#include <QMessageBox>

using DatabaseConnector = Database::DatabaseConnector;

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
        ui->statusLabel->setText("Connected");
        DatabaseConnector connector;
        QString userName = ui->userNameBox->toPlainText();
        QString userPassword = ui->userPasswordBox->toPlainText(); //"1234"
        if(userName.isEmpty() || userPassword.isEmpty()) {
            return;
        }
        QString validation = connector.VerifyUser(userName, userPassword) ? "Passed" : "Failed";
        ui->statusLabel->setText("Validation: " + validation);
    }
    catch(std::exception* e) {
        qDebug() << e->what();
        QMessageBox::information(0, "FAULT",  "Database connection could not be established.");
    }
}

void DataBaseTestWindow::on_loginButton_clicked(){

}
