#ifndef MAIN_CPP_CELL_INTERFACE_H
#define MAIN_CPP_CELL_INTERFACE_H

class Cell_interface{
public:
    virtual int* get_coord() = 0;
    virtual int get_condition() = 0;
    virtual char get_fill() = 0;
    virtual void set_condition(int cond) = 0;
    virtual void set_coord(int x, int y) = 0;
    virtual void set_fill(char value) = 0;
};

#endif //MAIN_CPP_CELL_INTERFACE_H
