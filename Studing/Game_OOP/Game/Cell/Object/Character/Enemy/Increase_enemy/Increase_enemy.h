//
// Created by danil on 22.10.2021.
//

#ifndef MAIN_CPP_INCREASE_ENEMY_H
#define MAIN_CPP_INCREASE_ENEMY_H

#include "../Enemy.h"

class Increase_enemy: public Enemy{
    void foo() override{};
    void take_equip(Object* equip) override{};
public:
    Increase_enemy();
    void move(Commands dir) override;
    //void add_health();
};


#endif //MAIN_CPP_INCREASE_ENEMY_H
