#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include <QMainWindow>

class QPushButton;
class QLabel;

class MainWindowView : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindowView(QWidget *parent = 0);
    ~MainWindowView();

    void setupUI(QMainWindow *MainWindow);
    void setupExitButton(QMainWindow *MainWindow);
    void setupInfoLabel();
    void setupMainWindow(QMainWindow *MainWindow);
    void setupWidget();
signals:

public slots:
    void on_pushbuttonClose_clicked();

private:
    QWidget *centralWidget;
    QLabel *labelApplicationInfo;
    QPushButton *pushbuttonClose;

};

#endif // MAINWINDOWVIEW_H
