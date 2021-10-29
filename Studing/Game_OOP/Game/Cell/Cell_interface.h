#ifndef MAIN_CPP_CELL_INTERFACE_H
#define MAIN_CPP_CELL_INTERFACE_H

#include "./Object/Object.h"

class Cell_interface{
public:
    virtual int* get_coord() = 0;
    virtual Object* get_object() = 0;
    virtual void set_object(Object* Entity) = 0;
};

#endif //MAIN_CPP_CELL_INTERFACE_H
