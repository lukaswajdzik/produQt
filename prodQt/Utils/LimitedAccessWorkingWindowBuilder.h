#ifndef FULLACCESSWORKINGWINDOWBUILDER_H
#define FULLACCESSWORKINGWINDOWBUILDER_H

#include <memory>
#include "Utils/WorkingWindowBuilder.h"

namespace Application{
    class ApplicationContext;
}

namespace Utils{
    class Constants;
}

class QMainWindow;

namespace Utils{

class LimitedAccessWorkingWindowBuilder : public WorkingWindowBuilder
{
public:
    using Const = Utils::Constants;

    LimitedAccessWorkingWindowBuilder(std::shared_ptr<Application::ApplicationContext>);
    ~LimitedAccessWorkingWindowBuilder() = default;

    void buildTableEditorView(MainWindowView *) override;
    void buildWeightTabView(MainWindowView *) override;
    WorkingTabsView* getWorkingWindow() override;

private:
    void buildWorkingWindow(MainWindowView *);

    WorkingTabsView* m_workingWindow;
    std::shared_ptr<Application::ApplicationContext> m_appContext;
};

}

#endif // FULLACCESSWORKINGWINDOWBUILDER_H
