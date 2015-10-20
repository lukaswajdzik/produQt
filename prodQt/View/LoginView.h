#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include <memory>
#include <View/workingwindow.h>

class QTabWidget;
class QLabel;
class QComboBox;
class QLineEdit;
class QVBoxLayout;
class QPushButton;
class LoginController;
class QSqlTableModel;
class MainWindowView;

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
    QVBoxLayout *m_verticalLayout;
    QSqlTableModel *m_userListModel;

    MainWindowView *m_mainWindow;

    std::shared_ptr<LoginController> m_controller;

    void createNewObjects(QWidget *parent);
    void setupTabWidget();
    void setupLoginPushbutton();
    void setupLabel();
    void setupLayout();
    void setupLayoutWidget();
    void setupObjectNames();
    void setupUserListInComboBox();
};

#endif // LOGINVIEW_H
