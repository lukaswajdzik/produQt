#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelDbInfo->setStyleSheet("QLabel { background-color : white; color : black; }");
    ui->labelDbInfo->clear();
}

void MainWindow::setDbLabelAsConnected()
{
    ui->labelDbInfo->setText("Połączono z bazą danych.");
    ui->labelDbInfo->setStyleSheet("QLabel { background-color : white; color : green; }");
}

void MainWindow::setDbLabelAsDisconected()
{
    ui->labelDbInfo->setText("Brak połączenia z bazą danych.");
    ui->labelDbInfo->setStyleSheet("QLabel { background-color : white; color : red; }");

}

void MainWindow::setDbLabelAsIsConnecting()
{
    ui->labelDbInfo->setText("Łączenie z bazą danych...");
    ui->labelDbInfo->setStyleSheet("QLabel { background-color : white; color : black; }");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ad = std::make_shared<AddUser>();
    ad->show();
}
