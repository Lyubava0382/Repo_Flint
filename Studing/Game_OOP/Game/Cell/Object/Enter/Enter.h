#ifndef MAIN_CPP_ENTER_H
#define MAIN_CPP_ENTER_H


#include "../Object.h"

class Enter: public Object{
    sf::Color color = sf::Color::White;
    Conditions type = ENTER;
    int position[2];
public:
    sf::Color get_color() override;
    void set_color(sf::Color color) override;
    Conditions get_type() override;
    int* get_position() override;
    void set_position(int x,int y) override;
};


#endif //MAIN_CPP_ENTER_H
