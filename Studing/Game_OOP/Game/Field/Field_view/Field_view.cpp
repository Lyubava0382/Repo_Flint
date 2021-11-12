#include "Field_view.h"

Field_view::Field_view(Size size): Field(size) {
    field.create(sf::VideoMode(this->get_width()*SIZE_CELL, this->get_height()*SIZE_CELL), "MyGame");
    it = this->createIterator();
    this->cells_view = new sf::RectangleShape*[this->get_height()*this->get_width()];
    int i = 0;
    float x,y;
    for(it->First();!it->IsDone();it->Next(),i++){
        x = (float)it->Current()->get_coord().first;
        y = (float)it->Current()->get_coord().second;
        cells_view[i] =new sf::RectangleShape();
        cells_view[i]->setSize({SIZE_CELL,SIZE_CELL});
        cells_view[i]->setPosition({y*SIZE_CELL,x*SIZE_CELL});
        set_color(it->Current()->get_object(),cells_view[i]);
        field.draw(*cells_view[i]);
    }
}

Field_view::~Field_view(){
    for(int i = 0; i < this->get_height()*this->get_width();i++){
        delete this->cells_view[i];
    }
    delete []this->cells_view;
}


void Field_view::render_field(Player *player, vector<Enemy *> &enemies) {
    int i;
    field.display();
    while (field.isOpen())
    {
        /*thread th([&](){
            movements_enemies();
        });*/

        movements_enemies(enemies);

        sf::Event event;
        while (field.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                this->close_field();
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Up){
                    player->move(TOP_STEP);
                }
                else if(event.key.code == sf::Keyboard::Down){
                    player->move(DOWN_STEP);
                }else if(event.key.code == sf::Keyboard::Left){
                    player->move(LEFT_STEP);
                }else if(event.key.code == sf::Keyboard::Right){
                    player->move(RIGHT_STEP);
                }
            }
        }

        field.clear();
        for(it->First(),i = 0;!it->IsDone();it->Next(),i++){
            set_color(it->Current()->get_object(),cells_view[i]);
            field.draw(*cells_view[i]);
        }

        field.display();

    }
    delete it;
}

void Field_view::set_color(Object* entity,sf::RectangleShape *cell){
    switch (entity->get_type()) {
        case PLAYER:
            cell->setFillColor(sf::Color::Blue);
            break;
        case EQUIPMENT:
            switch (dynamic_cast<Equipment*>(entity)->get_type_equip()) {
                case Equipment::ARMOR:
                    cell->setFillColor(sf::Color::Yellow);
                    break;
                case Equipment::HEALTH:
                    cell->setFillColor(sf::Color::Yellow);
                    break;
                case Equipment::WEAPON:
                    cell->setFillColor(sf::Color::Yellow);
                    break;
            }
            break;
        case EMPTY:
            cell->setFillColor(sf::Color::Green);
            break;
        case ENTER:
            cell->setFillColor(sf::Color::White);
            break;
        case EXIT:
            cell->setFillColor(sf::Color::Black);
            break;
        case PATHLESS:
            cell->setFillColor(sf::Color::Cyan);
            break;
        case ENEMY:
            switch (dynamic_cast<Enemy*>(entity)->get_type_enemy()) {
                case Enemy::SIMPLE:
                    cell->setFillColor(sf::Color::Red);
                    break;
                case Enemy::INCREASE:
                    cell->setFillColor(sf::Color::Magenta);
                    break;
                case Enemy::REPRODUCE:
                    cell->setFillColor(sf::Color::Transparent);
                    break;
            }
            break;
    }
};

void Field_view::close_field(){
    field.close();
};