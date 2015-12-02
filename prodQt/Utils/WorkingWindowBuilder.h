#ifndef WORKINGWINDOWTABSBUILDER_H
#define WORKINGWINDOWTABSBUILDER_H

#include "View/WorkingTabsView.h"

namespace Utils{


class WorkingWindowBuilder
{
public:
    virtual void buildTableEditorView(MainWindowView *) { }
    virtual void buildWeightTabView(MainWindowView *) { }
    virtual WorkingTabsView* getWorkingWindow() { return 0; }

protected:
    ~WorkingWindowBuilder() = default;
};

}

#endif // WORKINGWINDOWTABSBUILDER_H
