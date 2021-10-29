//
// Created by danil on 23.10.2021.
//

#include "Character.h"

sf::Color Character::get_color(){
    return this->color;
};
void Character::set_color(sf::Color color){
    this->color = color;
};
Conditions Character::get_type(){
    return this->type;
};
int* Character::get_position(){
    return this->position;
};
void Character::set_position(int x,int y){
    this->position[0] = x;
    this->position[1] = y;
};

int Character::get_attack(){
    return this->Attack;
};
int Character::get_protection(){
    return this->Protection;
};
int Character::get_health(){
    return this->Health;
};
void Character::set_attack(int attack){
    this->Attack = attack;
};
void Character::set_protection(int protection){
    this->Protection = protection;
};
void Character::set_health(int health){
    this->Health = health;
};

void Character::step(Directions direction,Conditions type){
    int x,y;
    switch (direction) {
        case (LEFT):
            std::cout << "left" << std::endl;
            break;
        case(RIGHT):
            std::cout << "right" << std::endl;
            break;
        case(TOP):
            std::cout << "top" << std::endl;
            break;
        case(DOWN):
            std::cout << "down" << std::endl;
            break;
    }

    switch (type) {
        case(EMPTY):
            break;
        case(PATHLESS):
            break;
        case(PLAYER):
            break;
        case(ENEMY):
            break;
        case(EQUIPMENT):
            break;
        case(ENTER):
            break;
        case(EXIT):
            break;
    }
}
