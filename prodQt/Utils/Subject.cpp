#include "Subject.h"
#include "Utils/Observer.h"

namespace Utils{

    void Subject::attach(std::shared_ptr<Observer> o)
    {
        m_observers->push_back(o);
    }

    void Subject::detach(std::shared_ptr<Observer> o)
    {
        m_observers->pop_back();
    }

    void Subject::notify()
    {
        for (const auto &a : *m_observers)
        {
            a->update(this);
        }

    }

}

