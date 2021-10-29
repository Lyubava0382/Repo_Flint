#ifndef MAIN_CPP_EXIT_H
#define MAIN_CPP_EXIT_H

#include "../Object.h"

class Exit: public Object{
    sf::Color color = sf::Color::Black;
    Conditions type = EXIT;
    int position[2];
public:
    sf::Color get_color() override;
    void set_color(sf::Color color) override;
    Conditions get_type() override;
    int* get_position() override;
    void set_position(int x,int y) override;
};


#endif //MAIN_CPP_EXIT_H
