#include "databasetestwindow.h"
#include "ui_databasetestwindow.h"
#include "Database/databaseconnector.h"
#include "Utils/blowfishprovider.h"

#include "External/blowfish.h"

#include <exception>
#include <QDebug>
#include <QMessageBox>
#include "gtest/gtest.h"

using DatabaseConnector = Database::DatabaseConnector;
typedef unsigned char byte;

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
    QString hash = ui->decodedTextField->toPlainText();
    QString password = Utils::BlowFishProvider::GetDbPasswordDecoded(hash);
    ui->encodedTextField->setText(password);

}

void DataBaseTestWindow::encodeClicked(){
    BLOWFISH bf("FEDCBA9876543210");
    std::string asdf = "BlowwFIshhhhhhhhhhh!";
    asdf = bf.Encrypt_CBC(asdf);
//    cout << "Encrypted: " << asdf << endl;
    ui->encodedTextField->setText(QString::fromStdString(asdf));
    asdf = bf.Decrypt_CBC(asdf);
//    cout << "Decrypted: " << asdf;
    ui->decodedTextField->setText(QString::fromStdString(asdf));

    asdf = bf.Encrypt_CBC(asdf);
    ui->encodedTextField_2->setText(QString::fromStdString(asdf));
    asdf = bf.Decrypt_CBC(asdf);
    ui->decodedTextField_2->setText(QString::fromStdString(asdf));

//    QString password = ui->encodedTextField->toPlainText();
//    QString hash = Utils::BlowFishProvider::GetDbPasswordEncoded(password);
//    ui->decodedTextField->setText(hash);
//    password = Utils::BlowFishProvider::GetDbPasswordDecoded(hash);
//    ui->encodedTextField_2->setText(password);
}

void DataBaseTestWindow::on_loginButton_clicked(){

}
