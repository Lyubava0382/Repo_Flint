#include "Enemy.h"

void Enemy::death(){
    this->notify(KILL_ENEMY);
};

Enemy::Type_enemy Enemy::get_type_enemy(){
    return type_enemy;
};