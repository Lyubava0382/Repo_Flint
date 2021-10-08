#include "Iterator.h"
using namespace std;

Iterator::Iterator(Cell** p_data, int height, int width):Field(p_data){
    max_width = width-1;
    max_height = height-1;
    cur_item = &Field[0][0];
    end_item = &Field[max_height][max_width];
}
void Iterator::First() {
    cur_item = &Field[0][0];
}
void Iterator::Next() {
    if(cur_width == max_width){
        this->cur_width = 0;
        this->cur_height++;
        this->cur_item = &(Field[cur_height][cur_width]);
    }else{
        cur_width++;
        this->cur_item = &(Field[cur_height][cur_width]);
    }
    //cout << this->Current()->get_fill() << ' ';
}
Cell* Iterator::Current() {
    return cur_item;
}

bool Iterator::IsDone() {
    return (cur_item == end_item);
}