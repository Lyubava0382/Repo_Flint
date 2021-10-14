#ifndef OOP_CELL_H
#define OOP_CELL_H

#include "Cell_interface.h"

class Cell: public Cell_interface{
    int coord[2];
    int condition;
    char fill;
public:
    Cell(int row = -1, int col =-1,char fill = 0,int condition = 0);
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    Cell(Cell&& other);
    Cell& operator=(Cell&& other);

    int* get_coord() override;
    int get_condition() override;
    char get_fill() override;
    void set_condition(int cond) override;
    void set_coord(int x, int y) override;
    void set_fill(char value) override;
};

#endif //OOP_CELL_H
