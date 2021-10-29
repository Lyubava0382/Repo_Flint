//
// Created by danil on 23.10.2021.
//

#ifndef MAIN_CPP_EMPTY_H
#define MAIN_CPP_EMPTY_H


#include "../Object.h"

class Empty: public Object{
    sf::Color color = sf::Color::Green;
    Conditions type = EMPTY;
    int position[2];
public:
    sf::Color get_color() override;
    void set_color(sf::Color color) override;
    Conditions get_type() override;
    int* get_position() override;
    void set_position(int x,int y) override;
};


#endif //MAIN_CPP_EMPTY_H
