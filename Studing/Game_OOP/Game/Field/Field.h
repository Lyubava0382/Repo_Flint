#ifndef OOP_FIELD_H
#define OOP_FIELD_H

#include <iostream>
#include "../Iterator/Iterator.h"
#include "../Cell/Object/Character/Enemy/Enemy.h"
#include <thread>
#include <chrono>
using namespace std;

class Field{
    Cell*** Cells;
    int height;
    int width;
public:
    enum Size{SMALL, MIDDLE, BIG, TEST};
    explicit Field(Size size = SMALL);
    Field(const Field& other);
    Field& operator=(const Field& other);
    Field(Field&& other);
    Field& operator=(Field&& other);
    ~Field();

    Iterator* createIterator();

    Cell* get_cell(int x,int y);
    Cell*** get_cells();
    int get_height();
    int get_width();

protected:
    Iterator* it;
    void movements_enemies(vector<Enemy *> enemyes);
};

#endif //OOP_FIELD_H
