
#include "Field.h"
#include "../Size_cell.h"


Field::Field(Size size){
    switch (size) {
        case SMALL:
            this->height = 320/SIZE_CELL;
            this->width = 680/SIZE_CELL;
            break;
        case MIDDLE:
            this->height = 480/SIZE_CELL;
            this->width = 800/SIZE_CELL;
            break;
        case BIG:
            this->height = 640/SIZE_CELL;
            this->width = 1080/SIZE_CELL;
            break;
        case TEST:
            this->height = 60/SIZE_CELL;
            this->width = 60/SIZE_CELL;
            break;
    }
    this->Cells = new Cell **[height];
    for (int i = 0; i < this->height; i++){
        this->Cells[i] = new Cell *[width];
        for (int j = 0; j < this->width; j++){
            Cells[i][j] = new Cell(i, j);
        }
    }
}
Field::Field(const Field& other):height(other.height),width(other.width){
    this->Cells = new Cell **[height];
    for (int i = 0; i < height; i++){
        this->Cells[i] = new Cell *[width];
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
        this->Cells = new Cell **[height];
        for (int i = 0; i < height; i++){
            Cells[i] = new Cell *[width];
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
        this->Cells = new Cell **[this->height];
        for(int i = 0; i < this->height; i++){
            this->Cells[i] = new Cell *[this->width];
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
        this->Cells = new Cell **[this->height];
        for(int i = 0; i < this->height; i++){
            this->Cells[i] = new Cell *[this->width];
            for(int j = 0; j < this->width;j++){
                this->Cells[i][j] = move(other.Cells[i][j]);
            }
        }
    }
    return *this;
}

Iterator* Field::createIterator(){
    return new Iterator(this->Cells, this->height, this->width);
}

Cell* Field::get_cell(int x,int y){
    return this->Cells[x][y];
}//Позволяет менять найденную ячейку

Cell*** Field::get_cells(){
    return this->Cells;
};

int Field::get_height(){
    return this->height;
}

int Field::get_width(){
    return this->width;
}

void Field::movements_enemies(vector<Enemy *> enemies) {
    for(int i = 0; i < enemies.size(); i++){
        enemies[i]->move(ANY_STEP);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
};

Field::~Field(){
    for(int i = 0; i < this->height; i++){
        for(int j = 0; j < this->width; j++){
            delete this->Cells[i][j];
        }
        delete[] this->Cells[i];
    }
    delete[] this->Cells;
}