#ifndef DATABASETESTWINDOW_H
#define DATABASETESTWINDOW_H

#include <QMainWindow>

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
};

#endif // DATABASETESTWINDOW_H
