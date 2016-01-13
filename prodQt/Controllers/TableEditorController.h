#ifndef TABLEEDITORCONTROLLER_H
#define TABLEEDITORCONTROLLER_H
#include <memory>

namespace Application{
    class ApplicationContext;
}
namespace Utils{
    class Observer;
}

class QWidget;
class MainWindowView;

class TableEditorController
{
public:
    TableEditorController(std::shared_ptr<Application::ApplicationContext>, MainWindowView*);
    ~TableEditorController();

    void showCategoryAddingView(Utils::Observer*);
    void showCategoryEditingView(Utils::Observer*);

private:
    std::shared_ptr<Application::ApplicationContext> m_appContext;
    MainWindowView* m_mainWindow;

    void showWidgetWithFocus(QWidget* categoryView);
};

#endif // TABLEEDITORCONTROLLER_H
