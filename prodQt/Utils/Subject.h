#ifndef SUBJECT_H
#define SUBJECT_H
#include <memory>
#include <vector>

namespace Utils{
    class Observer;

    class Subject
    {
    public:
        virtual ~Subject();
        virtual void attach(std::shared_ptr<Observer>);
        virtual void detach(std::shared_ptr<Observer>);
        virtual void notify();
    protected:
        Subject();
    private:
        std::vector<std::shared_ptr<Observer>> *m_observers;
    };
}

#endif // SUBJECT_H
