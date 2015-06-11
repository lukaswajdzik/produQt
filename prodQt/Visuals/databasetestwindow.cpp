#include "databasetestwindow.h"
#include "ui_databasetestwindow.h"
#include "Database/databaseconnector.h"

using DatabaseConnector = Database::DatabaseConnector;

DataBaseTestWindow::DataBaseTestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataBaseTestWindow)
{
    ui->setupUi(this);
    DatabaseConnector connector;
    bool isValid = connector.VerifyUser("", "");
}

DataBaseTestWindow::~DataBaseTestWindow()
{
    delete ui;
}
