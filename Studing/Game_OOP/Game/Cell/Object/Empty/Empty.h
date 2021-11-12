//
// Created by danil on 23.10.2021.
//

#ifndef MAIN_CPP_EMPTY_H
#define MAIN_CPP_EMPTY_H


#include "../Object.h"

class Empty: public Object{
    Conditions type;
    void interact(Object *&entity) override{};
    void take_equip(Object *equip) override{};
    int get_attack() override{return 0;};
    int get_protection() override{return 0;};
    int get_health() override{return 0;};
    void set_attack(int attack) override{};
    void set_protection(int protection) override{};
    void set_health(int health) override{};
    void addObserver(IObserver* o) override{};
    void removeObserver(IObserver* o) override{};
    void notify(Commands dir) override{};
    void move(Commands dir) override{};
public:
    Empty();
    Conditions get_type() override;
};


#endif //MAIN_CPP_EMPTY_H
