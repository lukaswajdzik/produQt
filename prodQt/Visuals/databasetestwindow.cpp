#include "databasetestwindow.h"
#include "ui_databasetestwindow.h"
#include "Database/databaseconnector.h"
#include "Utils/blowfishprovider.h"

#include <exception>
#include <QDebug>
#include <QMessageBox>


using DatabaseConnector = Database::DatabaseConnector;

DataBaseTestWindow::DataBaseTestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataBaseTestWindow) {
    ui->setupUi(this);
    connect ( ui->loginButton, SIGNAL( clicked() ), this, SLOT( loginButtonClicked() ) );
    connect ( ui->decodeButton, SIGNAL( clicked() ), this, SLOT( decodeClicked() ) );
    connect ( ui->encodeButton, SIGNAL( clicked() ), this, SLOT( encodeClicked() ) );
}

DataBaseTestWindow::~DataBaseTestWindow() {
    delete ui;
}

void DataBaseTestWindow::loginButtonClicked() {
    try {
        ui->statusLabel->setText("Connected_");
        DatabaseConnector connector;
        QString userName = ui->userNameBox->toPlainText();
        QString userPassword = ui->userPasswordBox->toPlainText(); //"1234"
        if(userName.isEmpty() || userPassword.isEmpty()) {
            return;
        }
        QString validation = connector.VerifyUser(userName, userPassword) ? "Passed" : "Failed";
        ui->statusLabel->setText("Validation: " + validation);
        logger.log("Data base OK!");
    }
    catch(std::exception& e) {
        qDebug() << e.what();
        logger.log("Data base exception rised!");
        QMessageBox::information(0, "FAULT",  "Database connection could not be established.");
    }
}

void DataBaseTestWindow::decodeClicked(){
    QString encodedPass = ui->decodedTextField->toPlainText();
    QString decodedPass = Utils::BlowFishProvider::GetDbPasswordDecoded(encodedPass);
    ui->encodedTextField->setText(decodedPass);

}

void DataBaseTestWindow::encodeClicked(){
    QString decodedPass = ui->encodedTextField->toPlainText();
    QString encodedPass = Utils::BlowFishProvider::GetDbPasswordEncoded(decodedPass);
    ui->decodedTextField->setText(encodedPass);
}

void DataBaseTestWindow::on_loginButton_clicked(){

}
