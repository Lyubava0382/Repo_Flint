#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include "../Cell/Cell.h"
#include "../Cell/Object/Character/Player/Player.h"
#include "../Cell/Object/Enter/Enter.h"
#include "../Iterator/Iterator.h"

class Field:public sf::RenderWindow{
    sf::RenderWindow field;
    Cell*** Cells;
    Player* player;
    int height;
    int width;
public:
    Field(int size = -1);
    Field(const Field& other);
    Field& operator=(const Field& other);
    Field(Field&& other);
    Field& operator=(Field&& other);
    ~Field();

    Iterator* createIterator();

    void EnterOut(int* cell_enter, int* cell_exit);
    void setSize(int size);
    Cell* get_cell(int x,int y);
    int get_height();
    void render_field();
    void get_type(int x, int y);
};

#endif //OOP_FIELD_H
