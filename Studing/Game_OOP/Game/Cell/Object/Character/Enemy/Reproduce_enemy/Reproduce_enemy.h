//
// Created by danil on 22.10.2021.
//

#ifndef MAIN_CPP_REPRODUCE_ENEMY_H
#define MAIN_CPP_REPRODUCE_ENEMY_H


#include "../Enemy.h"

class Reproduce_enemy: public Enemy{
    void foo() override{};
    void take_equip(Object* equip) override{};
public:
    Reproduce_enemy();
    void move(Commands dir) override;
    void add_enemy();
};

#endif //MAIN_CPP_REPRODUCE_ENEMY_H
