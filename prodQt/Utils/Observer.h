#ifndef OBSERVER_H
#define OBSERVER_H
#include <memory>

namespace Utils{
    class Subject;

    class Observer
    {
    public:
        virtual ~Observer(){}
        virtual void update(Subject* theChangedSubject) = 0;
    };

}

#endif // OBSERVER_H
