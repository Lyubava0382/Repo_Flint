//
// Created by danil on 18.10.2021.
//

#include "Equipment.h"

int* Equipment::get_state() {
    return this->state;
}

Equipment::Type_equip Equipment::get_type_equip(){
    return  this->type_equip;
};