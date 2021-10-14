#include <iostream>
#include "Field.h"
#include <SFML/Graphics.hpp>
using namespace std;

Field::Field(int height, int width):height(height),width(width){
    this->Cells = new Cell*[height];
    for (int i = 0; i < height; i++){
        this->Cells[i] = new Cell[width];
        for (int j = 0; j < width; j++){
            Cells[i][j] = Cell(i,j,'0');
        }
    }
}
Field::Field(const Field& other):height(other.height),width(other.width){
    Cells = new Cell*[height];
    for (int i = 0; i < height; i++){
        Cells[i] = new Cell[width];
        for (int j = 0; j < width; j++){
            Cell x = other.Cells[i][j];
            Cells[i][j] = x;
        }
    }
}
Field& Field::operator=(const Field& other){
    if(this != &other){
        height = other.height;
        width = other.width;
        for(int i = 0; i < this->height; i++){
            delete[] this->Cells[i];
        }
        delete[] this->Cells;
        this->Cells = new Cell*[height];
        for (int i = 0; i < height; i++){
            Cells[i] = new Cell[width];
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
        this->Cells = new Cell*[this->height];
        for(int i = 0; i < this->height; i++){
            this->Cells[i] = new Cell[this->width];
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
        this->Cells = new Cell*[this->height];
        for(int i = 0; i < this->height; i++){
            this->Cells[i] = new Cell[this->width];
            for(int j = 0; j < this->width;j++){
                this->Cells[i][j] = move(other.Cells[i][j]);
            }
        }
    }
    return *this;
}
Field::~Field(){
    for(int i = 0; i < this->height; i++){
        delete[] this->Cells[i];
    }
    delete[] this->Cells;
}
void Field::EnterOut(int* cell_enter, int* cell_out){
    if((cell_enter[0]-cell_out[0] == 0 && abs(cell_enter[1]-cell_out[1]) <= 1) ||
       (cell_enter[1]-cell_out[1] == 0 && abs(cell_enter[0]-cell_out[0]) <= 1)){
        throw -1;
    }
    Cells[cell_enter[0]][cell_enter[1]].set_fill('#');
    Cells[cell_out[0]][cell_out[1]].set_fill('*');
}
Iterator* Field::createIterator(){
    return new Iterator(this->Cells, this->height, this->width);
}
void Field::render_field(){

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML game");

    window.clear();

    sf::RectangleShape a;
    float height = 20;
    float width = 20;
    a.setSize({height,width});
    a.setPosition({0,0});
    a.setFillColor(sf::Color::Green);
    window.draw(a);

    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(a);
        window.display();
    }

    for (int i = 0; i < this->height; i++){
        for (int j = 0; j < this->width; j++){
            std::cout << this->Cells[i][j].get_fill() << ' ';
        }
        std::cout <<  '\n';
    }
}
Cell* Field::get_cell(int x,int y){
    return &this->Cells[y][x];
}//Позволяет менять найденную ячейку
int Field::get_height(){
    return this->height;
}
