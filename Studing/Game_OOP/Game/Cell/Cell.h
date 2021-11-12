#ifndef OOP_CELL_H
#define OOP_CELL_H

#include "./Object/Object.h"
#include "./Object/Empty/Empty.h"


class Cell{
    Object* Entity;
    std::pair<int,int> coord;
public:
    Cell(int row = 0, int col = 0);
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    Cell(Cell&& other);
    Cell& operator=(Cell&& other);
    ~Cell();
    std::pair<int,int> get_coord();
    Object*& get_object();
    void set_object(Object* Entity);
};

#endif //OOP_CELL_H
