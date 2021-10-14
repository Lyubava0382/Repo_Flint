#include <iostream>
#include "./Iterator/Iterator.h"
#include "./Field/Field.h"
#include <SFML/Graphics.hpp> //https://www.sfml-dev.org/tutorials/2.5/start-linux.php - про локальную установку SFML

int main()
{
    Field b = Field(2,2);
    Iterator* it = b.createIterator();
    b.render_field();
    for(it->Current();!it->IsDone();it->Next()){
        std::cout << it->Current()->get_fill() << ' ';
    }
    std::cout << it->Current()->get_fill() << ' ';
    /*sf::RenderWindow window(sf::VideoMode(800, 600), "SFML game");

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
    }*/

    return 0;
}
