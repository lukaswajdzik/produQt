#ifndef TABLEEDITORCONTROLLER_H
#define TABLEEDITORCONTROLLER_H
#include <memory>

namespace Application{
    class ApplicationContext;
}
class QWidget;
class MainWindowView;

class TableEditorController
{
public:
    TableEditorController(std::shared_ptr<Application::ApplicationContext>, MainWindowView*);
    ~TableEditorController();

    QWidget* getCategoryView();

private:
    std::shared_ptr<Application::ApplicationContext> m_appContext;
    MainWindowView* m_mainWindow;
};

#endif // TABLEEDITORCONTROLLER_H
