#ifndef MAIN_CPP_MEDIATOR_H
#define MAIN_CPP_MEDIATOR_H

#include "../src/Direction.h"

class ComponentMediator;
class Mediator {
public:
    virtual void Notify(ComponentMediator *sender, Direction dir) const = 0;
};

class ComponentMediator {
protected:
    Mediator *mediator;

public:
    ComponentMediator(Mediator *mediator = nullptr) : mediator(mediator) {
    }
    void set_mediator(Mediator *mediator) {
        this->mediator = mediator;
    }
};

/*class Component1 : public ComponentMediator {
public:
    void DoA() {
        std::cout << "Component 1 does A.\n";
        this->mediator->Notify(this, "A");
    }
    void DoB() {
        std::cout << "Component 1 does B.\n";
        this->mediator->Notify(this, "B");
    }
};*/

class Component2 : public ComponentMediator {
public:
    void DoC() {
        std::cout << "Component 2 does C.\n";
        this->mediator->Notify(this, "C");
    }
    void DoD() {
        std::cout << "Component 2 does D.\n";
        this->mediator->Notify(this, "D");
    }
};

/**
 * Конкретные Посредники реализуют совместное поведение, координируя отдельные
 * компоненты.
 */


#endif //MAIN_CPP_MEDIATOR_H
