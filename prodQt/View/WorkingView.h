#ifndef WORKINGVIEW_H
#define WORKINGVIEW_H
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

namespace Application {
    class ApplicationContext;
}

class WorkingView : public QWidget,
                    public IWorkingWindow
{
    Q_OBJECT
public:
    explicit WorkingView(std::shared_ptr<Application::ApplicationContext>, MainWindowView*);
    ~WorkingView();
    QWidget* getView() override;

signals:

public slots:
void on_pbLogin_clicked();
private:
    MainWindowView *m_mainWindow;
    std::shared_ptr<Application::ApplicationContext> m_appContext;

    QTabWidget *m_weightTab;
    QWidget *m_tab;
    QPushButton *m_pb;
    QComboBox *m_comboBoxUserSelection;
    QLineEdit *m_lineEditUserPassword;
    QWidget *m_layoutWidget;
    QVBoxLayout *m_verticalLayout;
    QVBoxLayout *m_verticalLayout1;
    QVBoxLayout *m_verticalLayout2;
    QSqlTableModel *m_userListModel;


};

#endif // WORKINGVIEW_H
