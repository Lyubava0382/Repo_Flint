#ifndef MAIN_CPP_ENEMY_H
#define MAIN_CPP_ENEMY_H

#include "../Character.h"

//абстрактный класс
class Enemy: public Character{
    void interact(Object *&entity) override{};
public:
    enum Type_enemy{SIMPLE, INCREASE, REPRODUCE};
    virtual Type_enemy get_type_enemy();
    virtual void death();
protected:
    Type_enemy type_enemy;
};


#endif //MAIN_CPP_ENEMY_H
