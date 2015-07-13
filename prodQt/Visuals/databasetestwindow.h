#ifndef DATABASETESTWINDOW_H
#define DATABASETESTWINDOW_H

#include <QMainWindow>
#include "Utils/logger.h"
#include "Database/databaseconnector.h"

using Logger = Utils::Logger;

namespace Ui {
class DataBaseTestWindow;
}

class DataBaseTestWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit DataBaseTestWindow(QWidget *parent = 0);
        ~DataBaseTestWindow();

    private:
        Ui::DataBaseTestWindow *ui;
        Logger& logger = Logger::getInstance();
        std::shared_ptr<Database::DatabaseConnector> DbCon;

public slots:
        void loginButtonClicked();

private slots:
        void on_loginButton_clicked();
};

#endif // DATABASETESTWINDOW_H
