#include "Mover.h"

#define MOVE_POSSIBLE turned_type != PLAYER && turned_type != ENTER && turned_type != PATHLESS
#define INTERACT_POSSIBLE turned_cell->get_object()->get_type() != EMPTY && turned_cell->get_object()->get_type() != PATHLESS && location->get_object()->get_type() == PLAYER

Mover::Mover(Field* field){
    this->field = field;
    this->entity = entity;
    this->location = set_location();
}

Cell* Mover::set_location(){
    Iterator* it = field->createIterator();
    for(it->First();!it->IsDone();it->Next()){
        if(it->Current()->get_object() == entity){
            this->location = it->Current();
            break;
        }
    }
    delete it;
    return this->location;
};


void Mover::set_object(IObservable &entity) {
    this->entity = dynamic_cast<Object*>(&entity);
    this->location = set_location();
}

void Mover::check_step(short sh_x,short sh_y) {
    Object *tmp = this->location->get_object();
    int x = location->get_coord().first;
    int y = location->get_coord().second;

    Cell *turned_cell = this->field->get_cells()[x + sh_x][y + sh_y];

    if (INTERACT_POSSIBLE) {
        location->get_object()->interact(turned_cell->get_object());
    }
    Conditions turned_type = turned_cell->get_object()->get_type();
    if (MOVE_POSSIBLE) {
        location->set_object(turned_cell->get_object());
        turned_cell->set_object(tmp);
    }
}

void Mover::dir_step(Commands direction){
    this->location = set_location();
    int x = location->get_coord().first;
    int y = location->get_coord().second;
    switch (direction) {
        case LEFT_STEP:
            if(y > 0){
                check_step(0,-1);
            }
            break;
        case RIGHT_STEP:
            if(y < field->get_width()-1){
                check_step(0,1);
            }
            break;
        case DOWN_STEP:
            if(x < field->get_height()-1){
                check_step(1,0);
            }
            break;
        case TOP_STEP:
            if(x > 0){
                check_step(-1,0);
            }
            break;
    }
}

void Mover::any_step() {
    dir_step(static_cast<Commands>(std::rand()%4));
}