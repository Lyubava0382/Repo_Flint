#include <iostream>
#include "./Game/Iterator/Iterator.h"
#include "./Game/Field/Field.h"
#include "./Game/Cell/Cell.h"
#include "./Game/Cell/Object/Enter/Enter.h"
#include "./Game/Cell/Object/Exit/Exit.h"
#include "./Game/Cell/Object/Character/Enemy/Enemy.h"
#include "./Game/Cell/Object/Character/Player/Player.h"
#include "./Game/Cell/Object/Character/Enemy/Type1/Type1.h"
#include "./Game/Cell/Object/Character/Enemy/Type2/Type2.h"
#include "./Game/Cell/Object/Character/Enemy/Type3/Type3.h"
#include <SFML/Graphics.hpp> //https://www.sfml-dev.org/tutorials/2.5/start-linux.php - про локальную установку SFML

class A{
    int value;
public:
    A(int v){
        value = v;
        std::cout << "Constructor A" << std::endl;
    }
    virtual int get_value(){
        return value;
    }
};

class B: public A{
public:
    B(int v):A(v){
        std::cout << "Constructor B" << std::endl;
    }
};




int main()
{
    enum Size{SMALL, MIDDLE, BIG, TEST};
    Field a(BIG);
    Cell* c = a.get_cell(1,1);

    Player main_player = Player();

    c->set_object(&main_player);
    a.render_field();

    /*B test(5);
    int q = test.get_value();
    std::cout << q;*/






    /*A a(5);
    std::cout << a.get_v();*/

    /*
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
*//*
        window.clear();
        window.draw(a);
        window.draw(b);
        window.display();*//*
    }*/

    return 0;
}
