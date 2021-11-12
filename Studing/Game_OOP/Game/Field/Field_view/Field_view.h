//
// Created by danil on 30.10.2021.
//

#ifndef MAIN_CPP_FIELD_VIEW_H
#define MAIN_CPP_FIELD_VIEW_H

#include "../Field.h"
#include "../../Size_cell.h"
#include "../../Move/Mover.h"
#include "../../Command/Command.h"
#include "../../Cell/Object/Character/Player/Player.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Field_view: public Field {
    sf::RenderWindow field;
    sf::RectangleShape** cells_view;
    void set_color(Object* entity, sf::RectangleShape *cell);
public:
    ~Field_view();
    explicit Field_view(Size size = SMALL);
    void render_field(Player *player, vector<Enemy*> &enemies);
    void close_field();
};


#endif //MAIN_CPP_FIELD_VIEW_H
