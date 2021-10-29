#ifndef OOP_ITERATOR_H
#define OOP_ITERATOR_H

#include "../Cell/Cell.h"

class Iterator{
    Cell* cur_item;
    Cell* end_item;
    Cell*** Field;
    int cur_height = 0;
    int cur_width = 0;
    int max_height;
    int max_width;
public:
    Iterator(Cell*** p_data, int height, int width);
    void First();
    void Next();
    Cell* Current();
    bool IsDone();
};

#endif //OOP_ITERATOR_H
