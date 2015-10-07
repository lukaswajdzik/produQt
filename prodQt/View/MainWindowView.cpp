#include "MainWindowView.h"

MainWindowView::MainWindowView(QWidget *parent) : QMainWindow(parent)
{
    setupMainWindow(this);
}

MainWindowView::~MainWindowView()
{

}

void MainWindowView::setupMainWindow(QMainWindow *MainWindow)
{
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QStringLiteral("MainWindow"));

    MainWindow->setWindowTitle("ProduQt");
    MainWindow->resize(1158, 750);
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QStringLiteral("centralWidget"));
    labelApplicationInfo = new QLabel(centralWidget);
    labelApplicationInfo->setObjectName(QStringLiteral("labelDbInfo"));
    labelApplicationInfo->setGeometry(QRect(20, 710, 500, 17));
    labelApplicationInfo->setText("Witaj, aplikacja została uruchomiona.");
    MainWindow->setCentralWidget(centralWidget);
    QFont font;
    font.setBold(true);
    labelApplicationInfo->setFont(font);
    QMetaObject::connectSlotsByName(MainWindow);
}
