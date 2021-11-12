#include <iostream>
#include "./Game/Game.h"

/*class A{
public:
    virtual void DoEn() = 0;
};

class B: public A{
private:
    void DoEn() override {
        std:: cout << "Eeeeee" << endl;
    };
};

class C:public A{
public:
    void DoEn() override {
        std:: cout << "Rrrrr" << endl;
    };
};*/


int main()
{
    Game game(2,4,5,Field::BIG);

    game.start_game();



    return 0;
}
