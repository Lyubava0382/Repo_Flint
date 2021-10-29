#include "Exit.h"

sf::Color Exit::get_color(){
    return this->color;
};
void Exit::set_color(sf::Color color){
    this->color = color;
};
Conditions Exit::get_type(){
    return type;
};

int* Exit::get_position() {
    return position;
}

void Exit::set_position(int x,int y) {
    position[0] = x;
    position[1] = y;
}