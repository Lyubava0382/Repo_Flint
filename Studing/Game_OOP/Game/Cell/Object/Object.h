#ifndef MAIN_CPP_OBJECT_H
#define MAIN_CPP_OBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../Observer/IObserver.h"
#include "../../Conditions.h"

//Интерфейс
class Object:public IObservable {
public:
    /*virtual sf::Texture get_texture() = 0;
    virtual sf::Texture set_texture() = 0;*/
    virtual Conditions get_type() = 0;
    virtual void interact(Object *&entity) = 0;
    virtual void take_equip(Object *equip) = 0;
    virtual int get_attack() = 0;
    virtual int get_protection() = 0;
    virtual int get_health() = 0;
    virtual void set_attack(int attack) = 0;
    virtual void set_protection(int protection) = 0;
    virtual void set_health(int health) = 0;
    virtual void move(Commands dir) = 0;
};


#endif //MAIN_CPP_OBJECT_H
