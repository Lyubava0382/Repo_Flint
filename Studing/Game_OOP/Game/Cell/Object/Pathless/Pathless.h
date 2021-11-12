//
// Created by danil on 29.10.2021.
//

#ifndef MAIN_CPP_PATHLESS_H
#define MAIN_CPP_PATHLESS_H

#include "../Object.h"

class Pathless: public Object{
    Conditions type = PATHLESS;
    void interact(Object *&entity) override{};
    void take_equip(Object *equip) override{};
    int get_attack() override{return 0;};
    int get_protection() override{return 0;};
    int get_health() override{return 0;};
    void set_attack(int attack) override{};
    void set_protection(int protection) override{};
    void set_health(int health) override{};
    void move(Commands dir) override{};
    void addObserver(IObserver* o) override{};
    void removeObserver(IObserver* o) override{};
    void notify(Commands dir) override{};
public:
    Pathless();
    Conditions get_type() override;
};


#endif //MAIN_CPP_PATHLESS_H
