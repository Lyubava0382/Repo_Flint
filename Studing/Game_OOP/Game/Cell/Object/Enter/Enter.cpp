#include "Enter.h"

sf::Color Enter::get_color(){
    return this->color;
};
void Enter::set_color(sf::Color color){
    this->color = color;
};
Conditions Enter::get_type(){
    return type;
};

int* Enter::get_position() {
    return position;
} ;
void Enter::set_position(int x,int y) {
    position[0] = x;
    position[1] = y;
};