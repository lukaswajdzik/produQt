#ifndef SUBJECT_H
#define SUBJECT_H
#include <memory>
#include <list>

namespace Utils{
    class Observer;

    class Subject
    {
    public:
        virtual ~Subject();
        virtual void attach(Observer*);
        virtual void detach(Observer*);
        virtual void notify();
    protected:
        Subject();
    private:
        std::list<Observer*> m_observers;
    };
}

#endif // SUBJECT_H
