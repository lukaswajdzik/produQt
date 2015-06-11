#include "databasetestwindow.h"
#include "ui_databasetestwindow.h"
#include "Database/databaseconnector.h"
#include <QDebug>

using DatabaseConnector = Database::DatabaseConnector;

DataBaseTestWindow::DataBaseTestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataBaseTestWindow)
{
    ui->setupUi(this);
    DatabaseConnector connector;
    QString validation = connector.VerifyUser("Krzysiek", "1234") ? "Passed" : "Failed";
    qDebug() << "Validation: " + validation;
}

DataBaseTestWindow::~DataBaseTestWindow()
{
    delete ui;
}
