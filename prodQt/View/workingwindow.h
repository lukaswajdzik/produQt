#ifndef WORKINGWINDOW
#define WORKINGWINDOW

class QWidget;

class IWorkingWindow
{
public:
    virtual ~IWorkingWindow() {}
    virtual QWidget* getView() = 0;
};

#endif // WORKINGWINDOW

