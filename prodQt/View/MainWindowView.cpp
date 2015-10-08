#include "MainWindowView.h"
#include <QLabel>
#include <QPushButton>
#include <QDebug>

MainWindowView::MainWindowView(QWidget *parent) : QMainWindow(parent)
{
    setupUI(this);
}

MainWindowView::~MainWindowView()
{
    qDebug() << "Program terminate!";
}

void MainWindowView::setupExitButton(QMainWindow *MainWindow)
{
    pushbuttonClose->setObjectName(QStringLiteral("pushbuttonClose"));
    pushbuttonClose->setText("ZAMKNIJ");
    pushbuttonClose->setGeometry(QRect(970, 0, 130, 30));
}

void MainWindowView::setupInfoLabel()
{
    labelApplicationInfo->setObjectName(QStringLiteral("labelDbInfo"));
    labelApplicationInfo->setGeometry(QRect(20, 710, 500, 17));
    labelApplicationInfo->setText("Witaj, aplikacja została uruchomiona.");
    QFont font;
    font.setBold(true);
    labelApplicationInfo->setFont(font);
}

void MainWindowView::setupMainWindow(QMainWindow *MainWindow)
{
    MainWindow->setWindowTitle("ProduQt");
    MainWindow->resize(1100, 750);
    MainWindow->setCentralWidget(centralWidget);
}

void MainWindowView::setupWidget()
{
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    centralWidget->setStyleSheet("background-color:black;");
}


void MainWindowView::setupUI(QMainWindow *MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QStringLiteral("MainWindow"));

    centralWidget = new QWidget(MainWindow);
    pushbuttonClose = new QPushButton(MainWindow);
    labelApplicationInfo = new QLabel(centralWidget);

    setupMainWindow(MainWindow);
    setupInfoLabel();
    setupExitButton(MainWindow);
    setupWidget();
    QMetaObject::connectSlotsByName(MainWindow);
}

void MainWindowView::on_pushbuttonClose_clicked()
{
    close();
}
