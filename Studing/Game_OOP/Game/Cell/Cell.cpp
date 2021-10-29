#include <iostream>
#include "Cell.h"
#include "./Object/Empty/Empty.h"
using namespace std;

Cell::Cell(int row, int col,const sf::Color fill,Conditions condition){
    this->setSize({20,20});
    this->setPosition({(float)row*20,(float)col*20});
    this->setFillColor(fill);
    this->coord[0] = row;
    this->coord[1] = col;
    this->type = condition;
    if(condition == EMPTY){
        *Entity = Empty();
    }
}
Cell::Cell(const Cell& other):type(other.type){
    this->setSize(other.getSize());
    this->setFillColor(other.getFillColor());
    this->type = other.type;
    this->Entity = other.Entity;
} //Обеспечат копирование
Cell& Cell::operator=(const Cell& other){
    if(this != &other){
        this->setSize(other.getSize());
        this->setFillColor(other.getFillColor());
        this->type = other.type;
        this->Entity = other.Entity;
    }
    return *this;
}                                  //ячеек
Cell::Cell(Cell&& other){
    swap(*this,other);
    swap(this->coord[0],other.coord[0]);
    swap(this->coord[1],other.coord[1]);
    swap(this->type,other.type);
}
Cell& Cell::operator=(Cell&& other){
    if(this != &other){
        swap(*this,other);
        swap(this->Entity,other.Entity);
        swap(this->coord[0],other.coord[0]);
        swap(this->coord[1],other.coord[1]);
        swap(this->type,other.type);
    }
    return *this;
}

Cell::~Cell(){

};

int* Cell::get_coord(){
    return this->coord;
}

Object* Cell::get_object(){
    return this->Entity;
}
void Cell::set_object(Object* Entity){
    this->Entity = Entity;
    this->setFillColor(Entity->get_color());
    this->type = Entity->get_type();
    Entity->set_position(coord[0],coord[1]);
}
