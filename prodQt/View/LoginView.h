#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include <memory>
#include <View/IWorkingWindow.h>

class QTabWidget;
class QLabel;
class QComboBox;
class QLineEdit;
class QVBoxLayout;
class QPushButton;
class LoginController;
class QSqlTableModel;
class MainWindowView;
class NumericKeyboard;
class QHBoxLayout;

namespace Application {
    class ApplicationContext;
}

class LoginView : public QWidget, public IWorkingWindow

{
    Q_OBJECT
public:
    explicit LoginView(std::shared_ptr<Application::ApplicationContext>,
                       MainWindowView*);
    ~LoginView();

    QWidget* getView() override;

    void setupPasswordLine();
signals:

public slots:
    void on_pbLogin_clicked();

private:
    QTabWidget *m_tabLogin;
    QWidget *m_tab;
    QPushButton *m_pbLogin;
    QComboBox *m_comboBoxUserSelection;
    QLineEdit *m_lineEditUserPassword;
    QWidget *m_layoutWidget;
    QWidget *m_keyboardWidget;
    QHBoxLayout *m_keyboardLayout;
    QVBoxLayout *m_verticalLayout;
    QSqlTableModel *m_userListModel;
    MainWindowView *m_mainWindow;
    std::shared_ptr<NumericKeyboard> m_keyboard;

    std::shared_ptr<LoginController> m_controller;

    void createNewObjects(QWidget *parent);
    void setupTabWidget();
    void setupLoginPushbutton();
    void setupLabel();
    void setupLayout();
    void setupWidgets();
    void setupObjectNames();
    void setupUserListInComboBox();
};

#endif // LOGINVIEW_H
