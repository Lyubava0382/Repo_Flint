//
// Created by danil on 23.10.2021.
//

#ifndef MAIN_CPP_CHARACTER_H
#define MAIN_CPP_CHARACTER_H

#include "../Object.h"

//Абстрактный класс для игрока и врага
class Character: public Object{
protected:
    enum Directions{LEFT,RIGHT,TOP,DOWN};
    sf::Color color;
    Conditions type;
    int position[2];
    int Attack;
    int Health;
    int Protection;
public:
    sf::Color get_color() override;
    void set_color(sf::Color color) override;
    Conditions get_type() override;
    int* get_position() override;
    void set_position(int x,int y) override;
    virtual int get_attack();
    virtual int get_protection();
    virtual int get_health();
    virtual void set_attack(int attack);
    virtual void set_protection(int protection);
    virtual void set_health(int health);
    virtual void step(Directions direction, Conditions type);
    virtual void foo() = 0;
};


#endif //MAIN_CPP_CHARACTER_H
