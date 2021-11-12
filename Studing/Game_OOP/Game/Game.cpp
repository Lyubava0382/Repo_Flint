#include <iostream>
#include "Game.h"

Game::Game(int count_enemies,int count_equip,int count_pathless,Field::Size size): IObserver() {
    this->field_view = new Field_view(size);
    this->field = dynamic_cast<Field*>(this->field_view);
    this->mover = new Mover(this->field);
    srand(time(0));
    create_enter();
    create_exit();
    create_enemyes(count_enemies);
    create_equipments(count_equip);
    create_pathless(count_pathless);
}

void Game::start_game() {
    field_view->render_field(player,enemies);
}

void Game::create_enter(){
    Cell* c;
    for(int i = 0; i < 1; i++){
        c = field->get_cell(rand()%(field->get_height()-2)+1, rand()%(field->get_width()-2)+1);
        if(c->get_object()->get_type() != EMPTY){
            i--;
            continue;
        }
        this->enter = new Enter;
        c->set_object(this->enter);
        this->create_player(c->get_coord());
    }
};

void Game::create_exit(){
    Cell* c;
    for(int i = 0; i < 1; i++){
        int y = 1 + rand()%(field->get_width()-2);
        int x = 1 + rand()%(field->get_height()-2);
        c = field->get_cell(x,y);
        if(c->get_object()->get_type() != EMPTY){
            i--;
            continue;
        }else if(field->get_cell(x-1,y)->get_object()->get_type() == ENTER
        || field->get_cell(x+1,y)->get_object()->get_type() == ENTER
        || field->get_cell(x,y-1)->get_object()->get_type() == ENTER
        || field->get_cell(x,y+1)->get_object()->get_type() == ENTER){
            i--;
            continue;
        }
    }
    this->exit = new Exit();
    c->set_object(this->exit);
};

void Game::create_player(pair<int, int> coord_enter) {
    this->player =new Player;
    Cell* c = field->get_cell(coord_enter.first,coord_enter.second+1);
    c->set_object(this->player);
    this->player->addObserver(this);
}

void Game::create_enemyes(int count){
    for(int i = 0; i < count; i++){
        this->add_enemy(static_cast<Enemy::Type_enemy>(rand()%3));
    }
};

void Game::add_enemy(Enemy::Type_enemy type) {
    Cell* c;
    c = field->get_cell(rand()%(field->get_height()-1), rand()%(field->get_width()-1));
    while (c->get_object()->get_type() != EMPTY){
        c = field->get_cell(rand()%(field->get_height()-1), rand()%(field->get_width()-1));
    }
    switch (type) {
        case Enemy::SIMPLE:
            enemies.push_back(new Simple_enemy());
            break;
        case Enemy::INCREASE:
            enemies.push_back(new Increase_enemy());
            break;
        case Enemy::REPRODUCE:
            enemies.push_back(new Reproduce_enemy());
            break;
    }
    enemies[enemies.size()-1]->addObserver(this);
    c->set_object(enemies[enemies.size()-1]);
}

void Game::remove_enemy(Enemy &enemy){
    enemies.erase(remove(enemies.begin(),enemies.end(),&enemy),enemies.end());
};

void Game::create_equipments(int count){
    for(int i = 0; i < count; i++) {
        this->add_equipments(static_cast<Equipment::Type_equip>(rand() % 3));
    }
}

void Game::add_equipments(Equipment::Type_equip type){
    Cell* c;
    c = field->get_cell(rand()%(field->get_height()-1), rand()%(field->get_width()-1));
    while (c->get_object()->get_type() != EMPTY){
        c = field->get_cell(rand()%(field->get_height()-1), rand()%(field->get_width()-1));
    }
    switch (type) {
        case Equipment::WEAPON:
            equipment.push_back(new Weapon());
            break;
        case Equipment::ARMOR:
            equipment.push_back(new Armor());
            break;
        case Equipment::HEALTH:
            equipment.push_back(new Health());
            break;
    }
    c->set_object(equipment[equipment.size()-1]);
}

void Game::create_pathless(int count){
    Cell* c;
    for(int i = 0; i < count; i++){
        c = field->get_cell(rand()%(field->get_height()-1), rand()%(field->get_width()-1));
        Conditions type = c->get_object()->get_type();
        while (type != EMPTY || type == ENEMY || type == ENTER || type == EXIT || type == EQUIPMENT){
            c = field->get_cell(rand()%(field->get_height()-1), rand()%(field->get_width()-1));
            type = c->get_object()->get_type();
        }
        pathless.push_back(new Pathless());
        c->set_object(pathless[i]);
    }
};

Game::~Game() {
    delete field_view;
}

void Game::update(Commands command, IObservable &entity) {
    switch (command) {
        case KILL_ENEMY:
            this->remove_enemy(dynamic_cast<Enemy&>(entity));
            break;
        case REP:
            this->add_enemy(Enemy::SIMPLE);
            break;
        case EXIT_GAME:
            field_view->close_field();
            break;
        default:
            if(command == ANY_STEP){
                this->mover->set_object(entity);
                mover->any_step();
            }else{
                this->mover->set_object(entity);
                mover->dir_step(command);
            }
    }
}
