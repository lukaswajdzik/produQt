#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setDbLabelAsIsConnecting();
    void setDbLabelAsConnected();
    void setDbLabelAsDisconected();

    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif
