#ifndef OOP_CELL_H
#define OOP_CELL_H

#include "Cell_interface.h"
#include <SFML/Graphics.hpp>
#include "./Object/Object.h"


class Cell: public Cell_interface, public sf::RectangleShape{
    Object* Entity;
    int coord[2];
    Conditions type;
public:
    Cell(int row = 0, int col = 0,const sf::Color fill = sf::Color::Green,Conditions condition = EMPTY);
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    Cell(Cell&& other);
    Cell& operator=(Cell&& other);
    ~Cell();

    int* get_coord() override;
    Object* get_object() override;
    void set_object(Object* Entity) override;
};

#endif //OOP_CELL_H
