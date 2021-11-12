#ifndef MAIN_CPP_MOVER_H
#define MAIN_CPP_MOVER_H

#include "../Field/Field.h"
#include "../Commands.h"

class Mover{
    Field* field;
    Object* entity;
    Cell* location;
    Cell* set_location();
    void check_step(short sh_x,short sh_y);
public:
    Mover(Field* field);
    void set_object(IObservable &entity);
    void dir_step(Commands direction);
    void any_step();
};


#endif //MAIN_CPP_MOVER_H
