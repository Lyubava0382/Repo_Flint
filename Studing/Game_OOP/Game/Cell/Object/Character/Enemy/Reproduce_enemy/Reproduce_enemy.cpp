//
// Created by danil on 22.10.2021.
//

#include "Reproduce_enemy.h"

Reproduce_enemy::Reproduce_enemy(){
    this->type = ENEMY;
    this->type_enemy = REPRODUCE;
    Attack = 1;
    Health = 1;
    Protection = 1;
    count_step = 0;
}

void Reproduce_enemy::move(Commands dir) {
    count_step++;
    if(count_step == 200){
        this->add_enemy();
        count_step = 0;
    }
    this->notify(dir);

}

void Reproduce_enemy::add_enemy() {
    this->notify(REP);
}