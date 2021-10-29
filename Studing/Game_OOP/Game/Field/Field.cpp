#include <iostream>
#include "Field.h"
#include "../Cell/Object/Enter/Enter.h"
#include "../Cell/Object/Exit/Exit.h"
#include <SFML/Graphics.hpp>
using namespace std;

Field::Field(int size){
    if(size == -1){
        this->height = 200/20;
        this->width = 200/20;
    }
    else if(size == 0){
        this->height = 600/20;
        this->width = 400/20;
    }else if (size == 1) {
        this->height = 800/20;
        this->width = 600/20;
    }
    else if (size == 2) {
        this->height = 1000/20;
        this->width = 800/20;
    }else if (size == 3) {
        this->height = 60/20;
        this->width = 60/20;
    }

    this->Cells = new Cell**[height];
    for (int i = 0; i < this->height; i++){
        this->Cells[i] = new Cell*[width];
        for (int j = 0; j < this->width; j++){
            Cells[i][j] =new Cell(i,j);
        }
    }
}
Field::Field(const Field& other):height(other.height),width(other.width){
    this->Cells = new Cell**[height];
    for (int i = 0; i < height; i++){
        this->Cells[i] = new Cell*[width];
        for (int j = 0; j < width; j++){
            this->Cells[i][j] = other.Cells[i][j];
        }
    }
}
Field& Field::operator=(const Field& other){
    if(this != &other){
        for(int i = 0; i < this->height; i++){
            delete[] this->Cells[i];
        }
        delete[] this->Cells;
        height = other.height;
        width = other.width;
        this->Cells = new Cell**[height];
        for (int i = 0; i < height; i++){
            Cells[i] = new Cell*[width];
            for (int j = 0; j < width; j++){
                Cells[i][j] = other.Cells[i][j];
            }
        }
    }
    return *this;
}
Field::Field(Field&& other){
    if(this != &other){
        this->height = other.height;
        this->width = other.width;
        this->Cells = new Cell**[this->height];
        for(int i = 0; i < this->height; i++){
            this->Cells[i] = new Cell*[this->width];
            for(int j = 0; j < this->width;j++){
                this->Cells[i][j] = move(other.Cells[i][j]);
            }
        }
    }
}
Field& Field::operator=(Field&& other){
    if(this != &other){
        this->height = other.height;
        this->width = other.width;
        this->Cells = new Cell**[this->height];
        for(int i = 0; i < this->height; i++){
            this->Cells[i] = new Cell*[this->width];
            for(int j = 0; j < this->width;j++){
                this->Cells[i][j] = move(other.Cells[i][j]);
            }
        }
    }
    return *this;
}

Field::~Field(){
    for(int i = 0; i < this->height; i++){
        for(int j = 0; j < this->width; j++){
            delete this->Cells[i][j];
        }
        delete[] this->Cells[i];
    }
    delete[] this->Cells;
}
void Field::EnterOut(int* cell_enter, int* cell_exit){
    if((cell_enter[0] - cell_exit[0] == 0 && abs(cell_enter[1] - cell_exit[1]) <= 1) ||
       (cell_enter[1] - cell_exit[1] == 0 && abs(cell_enter[0] - cell_exit[0]) <= 1)){
        throw -1;
    }
}

Iterator* Field::createIterator(){
    return new Iterator(this->Cells, this->height, this->width);
}

void Field::render_field(){
    this->field.create(sf::VideoMode(this->height*20, this->width*20), "SFML game");
    Iterator* it = this->createIterator();
    for(it->First();!it->IsDone();it->Next()){
        this->field.draw(*(it->Current()));
    }
    this->field.draw(*(it->Current()));

    this->field.display();
    int i = 5;//player->get_position()[0];
    int j = 10;//player->get_position()[1];
    while (this->field.isOpen())
    {
        sf::Event event;
        while (this->field.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->field.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Up){

                }else if(event.key.code == sf::Keyboard::Down){
                    std::cout << "Down!" << std::endl;
                }else if(event.key.code == sf::Keyboard::Left){
                    std::cout << "Left!" << std::endl;
                }else if(event.key.code == sf::Keyboard::Right){
                    std::cout << "Right!" << std::endl;
                }
        }

        field.clear();
        for(it->First();!it->IsDone();it->Next()){
            this->field.draw(*(it->Current()));
        }
        this->field.draw(*(it->Current()));
        this->field.display();

    }
    delete it;
}

Cell* Field::get_cell(int x,int y){
    return this->Cells[y][x];
}//Позволяет менять найденную ячейку

void Field::setSize(int size) {
    if(size == 0){
        this->height = 600/20;
        this->width = 400/20;
    }else if (size == 1) {
        this->height = 800/20;
        this->width = 600/20;
    }
    else if (size == 2) {
        this->height = 1000/20;
        this->width = 800/20;
    }
}

int Field::get_height(){
    return this->height;
}
