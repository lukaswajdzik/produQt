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
class QGridLayout;

namespace Application {
    class ApplicationContext;
}

class WorkingTabsView : public QWidget,
                        public IWorkingWindow
{
    Q_OBJECT
public:
    explicit WorkingTabsView(std::shared_ptr<Application::ApplicationContext>, MainWindowView*);
    ~WorkingTabsView();
    QWidget* getView() override;

    void addTab(QWidget*, QString);
signals:

public slots:
void on_pbLogin_clicked();
private:
    MainWindowView *m_mainWindow;
    std::shared_ptr<Application::ApplicationContext> m_appContext;

    QTabWidget *m_tabWidget;
    QWidget *m_layoutWidget;
};

#endif // WORKINGVIEW_H
