#include <iostream>
#include "./Iterator/Iterator.h"
#include "./Field/Field.h"

int main()
{
    Field b = Field(2,2);
    Iterator* it = b.createIterator();
    b.render_field();
    for(it->Current();!it->IsDone();it->Next()){
        std::cout << it->Current()->get_fill() << ' ';
    }
    std::cout << it->Current()->get_fill() << ' ';
    return 0;
}
