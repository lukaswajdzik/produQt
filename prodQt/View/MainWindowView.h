#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include <QMainWindow>
#include <memory>
#include "Utils/Observer.h"

class QPushButton;
class QLabel;
class QFrame;
class QGridLayout;
class MainWindowController;
class IWorkingWindow;
class QGraphicsOpacityEffect;
class QPropertyAnimation;

namespace Application {
    class ApplicationContext;
}

class MainWindowView : public QMainWindow,
                       public Utils::Observer
{
    Q_OBJECT
public:
    explicit MainWindowView(std::shared_ptr<Application::ApplicationContext>,
                            QWidget* = 0);
    ~MainWindowView();

    void setUserInfoText(QString p_text, QString p_color = "black");
    void update(Utils::Subject*) override;
signals:

private slots:
    void on_pushbuttonClose_clicked();

private:
    std::shared_ptr<MainWindowController> m_controller;
    std::shared_ptr<Application::ApplicationContext> m_appContext;

    QWidget *m_centralWidget;
    QLabel *m_labelApplicationInfo;
    QPushButton *m_pushbuttonClose;
    QGridLayout *m_layout;
    QFrame *m_line;
    QGraphicsOpacityEffect *m_opacityForWindow;
    QGraphicsOpacityEffect *m_opacityForText;
    QPropertyAnimation *m_animationForWindow;
    QPropertyAnimation *m_animationForInfoText;
    IWorkingWindow *m_workingWindow;

    void createNewObjects(QMainWindow *MainWindow);
    void setupElements(QMainWindow *MainWindow);
    void setupUI(QMainWindow *MainWindow);
    void setupExitButton();
    void setupInfoLabel();
    void setupMainWindow(QMainWindow *MainWindow);
    void setupWidget();
    void setupLine();
    void setupAnimationEffectsForWindow();
    void setAnimationForInfoText();
    void showLoginPage();
    void clearWorkingWindow();
};

#endif // MAINWINDOWVIEW_H
