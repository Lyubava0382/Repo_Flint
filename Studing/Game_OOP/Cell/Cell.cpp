#include <iostream>
#include "Cell.h"
using namespace std;

Cell::Cell(int row, int col,char fill,int condidion){
    this->coord[0] = row;
    this->coord[1] = col;
    this->fill = fill;
    this->condition = condidion;
}
Cell::Cell(const Cell& other):condition(other.condition),fill(other.fill){
    this->coord[0] = other.coord[0];
    this->coord[1] = other.coord[1];
} //Обеспечат копирование
Cell& Cell::operator=(const Cell& other){
    if(this != &other){
        this->coord[0] = other.coord[0];
        this->coord[1] = other.coord[1];
        this->condition = other.condition;
        this->fill = other.fill;
    }
    return *this;
}                                  //ячеек
Cell::Cell(Cell&& other){
swap(this->coord[0],other.coord[0]);
swap(this->coord[1],other.coord[1]);
swap(this->condition,other.condition);
swap(this->fill,other.fill);
}
Cell& Cell::operator=(Cell&& other){
    if(this != &other){
        swap(this->coord[0],other.coord[0]);
        swap(this->coord[1],other.coord[1]);
        swap(this->condition,other.condition);
        swap(this->fill,other.fill);
    }
    return *this;
}

int* Cell::get_coord(){
    return this->coord;
}
int Cell::get_condition(){
    return this->condition;
}
char Cell::get_fill(){
    return this->fill;
}
void Cell::set_condition(int cond){
    this->condition = cond;
}
void Cell::set_coord(int x, int y){
    this->coord[0] = x;
    this->coord[1] = y;
}
void Cell::set_fill(char value){
    this->fill = value;
}