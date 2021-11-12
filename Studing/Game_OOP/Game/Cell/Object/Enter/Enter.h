#ifndef MAIN_CPP_ENTER_H
#define MAIN_CPP_ENTER_H


#include "../Object.h"
#include "../Character/Player/Player.h"

class Enter: public Object{
    Conditions type;
    void interact(Object *&entity) override {};
    virtual void take_equip(Object *equip) override{};
    virtual int get_attack() override {return 0;};
    virtual int get_protection() override {return 0;};
    virtual int get_health() override {return 0;};
    virtual void set_attack(int attack) override{};
    virtual void set_protection(int protection) override{};
    virtual void set_health(int health) override{};
    void addObserver(IObserver* o) override{};
    void removeObserver(IObserver* o) override{};
    void notify(Commands dir) override{};
    void move(Commands dir) override{};
public:
    Enter();
    Conditions get_type() override;
};


#endif //MAIN_CPP_ENTER_H
