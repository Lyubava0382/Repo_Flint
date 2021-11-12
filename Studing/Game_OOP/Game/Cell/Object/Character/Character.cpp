//
// Created by danil on 23.10.2021.
//

#include "Character.h"

void Character::addObserver(IObserver *o) {
    observers.push_back(o);
}
void Character::removeObserver(IObserver *o) {
    observers.erase(remove(observers.begin(),observers.end(),o),observers.end());
}

void Character::notify(Commands dir) {
    for(auto o: observers){
        o->update(dir,*this);
    }
}

void Character::move(Commands dir) {
    this->notify(dir);
}

Conditions Character::get_type(){
    return this->type;
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
