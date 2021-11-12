#include "Health.h"

Health::Health() {
    type = EQUIPMENT;
    type_equip = HEALTH;
    state[WEAPON] = 0;
    state[ARMOR] = 0;
    state[HEALTH] = 1;
}