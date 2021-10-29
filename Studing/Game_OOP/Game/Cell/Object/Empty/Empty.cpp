//
// Created by danil on 23.10.2021.
//

#include "Empty.h"

sf::Color Empty::get_color(){
    return this->color;
};
void Empty::set_color(sf::Color color){
    this->color = color;
};
Conditions Empty::get_type(){
    return type;
};

int* Empty::get_position() {
    return position;
}

void Empty::set_position(int x,int y) {
    position[0] = x;
    position[1] = y;
}