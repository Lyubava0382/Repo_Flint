#ifndef MAIN_CPP_EQUIPMENT_H
#define MAIN_CPP_EQUIPMENT_H

#include "../../Cell.h"
#include "Equipment_interface.h"

class Equipment: public Cell,public Equipment_interface{
    enum Type{WEAPON, ARMOR, BOOSTER};
public:
    Equipment(float row = 0, float col = 0,const sf::Color fill = sf::Color::Yellow, Conditions condition = EMPTY):Cell(row,col,fill,condition){};
};


#endif //MAIN_CPP_EQUIPMENT_H
