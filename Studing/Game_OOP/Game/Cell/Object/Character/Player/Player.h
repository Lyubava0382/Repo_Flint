#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include "../Character.h"
#include "../Enemy/Enemy.h"
#include "../../Empty/Empty.h"
#include "../../Equipment/Equipment.h"
#include "../../Equipment/Armor/Armor.h"
#include "../../Equipment/Weapon//Weapon.h"
#include "../../Equipment/Health//Health.h"

class Player: public Character{
    std::vector <Object*> equipment;
    void foo() override{};
public:
    Player();
    void take_equip(Object *equip) override;
    void interact(Object *&entity) override;
    void exit();
    //void figth();
};


#endif //MAIN_CPP_PLAYER_H
