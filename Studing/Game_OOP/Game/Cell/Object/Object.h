#ifndef MAIN_CPP_OBJECT_H
#define MAIN_CPP_OBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

enum Conditions{
    EMPTY,
    PATHLESS,
    PLAYER,
    ENEMY,
    EQUIPMENT,
    ENTER,
    EXIT
};

//Интерфейс
class Object {
public:
    /*virtual sf::Texture get_texture() = 0;
    virtual sf::Texture set_texture() = 0;*/
    virtual sf::Color get_color() = 0;
    virtual void set_color(sf::Color color) = 0;
    virtual Conditions get_type() = 0;
    virtual int* get_position() = 0;
    virtual void set_position(int x,int y) = 0;
};


#endif //MAIN_CPP_OBJECT_H
