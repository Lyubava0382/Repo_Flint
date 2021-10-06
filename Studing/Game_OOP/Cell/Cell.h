#ifndef OOP_CELL_H
#define OOP_CELL_H

class Cell{
    int coord[2];
    int condition;
    char fill;
public:
    Cell(int row = -1, int col =-1,char fill = 0,int condidion = 0);
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);
    Cell(Cell&& other);
    Cell& operator=(Cell&& other);

    int* get_coord();
    int get_condition();
    char get_fill();
    void set_condition(int cond);
    void set_coord(int x, int y);
    void set_fill(char value);
};

#endif //OOP_CELL_H
