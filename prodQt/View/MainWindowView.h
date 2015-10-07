#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include <QMainWindow>
#include <QtWidgets/QLabel>

class MainWindowView : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindowView(QWidget *parent = 0);
    ~MainWindowView();

    void setupMainWindow(QMainWindow *MainWindow);
signals:

public slots:

private:
    QWidget *centralWidget;
    QLabel *labelApplicationInfo;

};

#endif // MAINWINDOWVIEW_H
