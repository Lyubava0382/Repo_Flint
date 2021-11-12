#include "Weapon.h"

Weapon::Weapon(){
    type = EQUIPMENT;
    type_equip = WEAPON;
    state[WEAPON] = 1;
    state[ARMOR] = 0;
    state[HEALTH] = 0;
}