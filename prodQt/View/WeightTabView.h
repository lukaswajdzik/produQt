#ifndef WEIGHTTABVIEW_H
#define WEIGHTTABVIEW_H

#include <QWidget>
#include "View/IWorkingWindow.h"
#include <memory>

class QPushButton;
class MainWindowView;
class QComboBox;
class QLineEdit;
class QGridLayout;
class QVBoxLayout;

namespace Application {
    class ApplicationContext;
}

class WeightTabView : public QWidget,
                      public IWorkingWindow
{
    Q_OBJECT
public:
    explicit WeightTabView(std::shared_ptr<Application::ApplicationContext>, MainWindowView*);
    ~WeightTabView();
    QWidget* getView() override;

signals:

public slots:

private:
    MainWindowView *m_mainWindow;
    std::shared_ptr<Application::ApplicationContext> m_appContext;
    QWidget *m_weightTab;
    QPushButton *m_pb;
    QComboBox *m_comboBoxUserSelection;
    QLineEdit *m_lineEditUserPassword;

    QGridLayout *m_mainLayout;
    QVBoxLayout *m_leftSideLayout;
    QVBoxLayout *m_rightSideLayout;
};

#endif // WEIGHTTABVIEW_H
