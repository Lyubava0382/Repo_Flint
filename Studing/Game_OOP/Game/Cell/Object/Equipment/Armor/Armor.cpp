#include "Armor.h"

Armor::Armor() {
    type = EQUIPMENT;
    type_equip = ARMOR;
    state[WEAPON] = 0;
    state[ARMOR] = 1;
    state[HEALTH] = 0;
}