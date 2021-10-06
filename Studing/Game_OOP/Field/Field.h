#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include "../Cell/Cell.h"
#include "../Iterator/Iterator.h"

class Field{
    Cell** Cells;
    int height;
    int width;
public:
    Field(int height = 0, int width = 0);
    Field(const Field& other);
    Field& operator=(const Field& other);
    Field(Field&& other);
    Field& operator=(Field&& other);
    ~Field();
    void EnterOut(int* cell_enter, int* cell_out);
    Iterator* createIterator();
    void render_field();
    Cell* get_cell(int x,int y);
    int get_height();

};

#endif //OOP_FIELD_H
