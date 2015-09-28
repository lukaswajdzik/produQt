#ifndef IUSER
#define IUSER

#include <functional>

class IUserAddingController
{
public:
    virtual ~IUserAddingController() {}
    virtual void setCloseAction(std::function<void(void)>) = 0;
    virtual void process() = 0;
};

#endif // IUSER
