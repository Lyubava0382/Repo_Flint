#include <iostream>
#include "Cell.h"
#include "./Object/Empty/Empty.h"
using namespace std;

Cell::Cell(int row, int col) {
    this->coord.first = row;
    this->coord.second = col;
    this->Entity = new Empty();
}
Cell::Cell(const Cell& other){
    this->Entity = other.Entity;
} //Обеспечат копирование
Cell& Cell::operator=(const Cell& other){
    if(this != &other){
        this->Entity = other.Entity;
    }
    return *this;
}                                  //ячеек
Cell::Cell(Cell&& other){
    swap(*this,other);
    swap(this->Entity,other.Entity);
    swap(this->coord.first,other.coord.first);
    swap(this->coord.second,other.coord.second);
}
Cell& Cell::operator=(Cell&& other){
    if(this != &other){
        swap(*this,other);
        swap(this->Entity,other.Entity);
        swap(this->coord.first,other.coord.first);
        swap(this->coord.second,other.coord.second);
    }
    return *this;
}

Cell::~Cell(){
    delete Entity;
};

std::pair<int,int> Cell::get_coord(){
    return this->coord;
}

Object *& Cell::get_object(){
    return this->Entity;
}
void Cell::set_object(Object* Entity){
    this->Entity = Entity;
}
