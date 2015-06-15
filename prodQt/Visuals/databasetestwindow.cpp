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
    try {
        DatabaseConnector connector;
        QString validation = connector.VerifyUser("Krzysiek", "1234") ? "Passed" : "Failed";
        qDebug() << "Validation: " + validation;
    }
    catch(std::exception* e) {
        qDebug() << e->what();
        QMessageBox::information(0, "FAULT",  "Database connection could not be established.");
    }
}

DataBaseTestWindow::~DataBaseTestWindow() {
    delete ui;
}
