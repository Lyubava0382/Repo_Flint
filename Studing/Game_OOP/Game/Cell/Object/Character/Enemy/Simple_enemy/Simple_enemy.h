//
// Created by danil on 22.10.2021.
//

#ifndef MAIN_CPP_SIMPLE_ENEMY_H
#define MAIN_CPP_SIMPLE_ENEMY_H

#include "../Enemy.h"

class Simple_enemy: public Enemy{
    void foo() override{};
    void take_equip(Object* equip) override{};
public:
    Simple_enemy();
};


#endif //MAIN_CPP_SIMPLE_ENEMY_H
