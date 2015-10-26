#include "Subject.h"
#include "Utils/Observer.h"

namespace Utils{

Subject::Subject()
{
}

Subject::~Subject()
{
}

void Subject::attach(Observer *o)
    {
        m_observers.push_back(o);
    }

    void Subject::detach(Observer *o)
    {
        m_observers.pop_back();
    }

    void Subject::notify()
    {
        for (const auto &observer : m_observers)
        {
            observer->update(this);
        }

    }

}

