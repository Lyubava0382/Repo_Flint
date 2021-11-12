//
// Created by danil on 22.10.2021.
//

#include "Increase_enemy.h"

Increase_enemy::Increase_enemy(){
    this->type = ENEMY;
    this->type_enemy = INCREASE;
    Attack = 1;
    Health = 1;
    Protection = 1;
    count_step = 0;
}

void Increase_enemy::move(Commands dir) {
    count_step++;
    if(count_step == 200){
        this->set_health(this->Health+1);
        count_step = 0;
        std::cout << Health << std::endl;
    }
    this->notify(dir);

}
