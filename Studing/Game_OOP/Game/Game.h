#ifndef MAIN_CPP_GAME_H
#define MAIN_CPP_GAME_H

#include <iostream>
#include <vector>
#include "./Iterator/Iterator.h"
#include "./Observer/IObserver.h"
#include "./Field/Field_view/Field_view.h"
#include "./Cell/Cell.h"
#include "./Cell/Object/Enter/Enter.h"
#include "./Cell/Object/Exit/Exit.h"
#include "./Cell/Object/Character/Enemy/Enemy.h"
#include "./Cell/Object/Character/Player/Player.h"
#include "./Cell/Object/Equipment/Equipment.h"
#include "./Cell/Object/Character/Enemy/Simple_enemy/Simple_enemy.h"
#include "./Cell/Object/Character/Enemy/Increase_enemy/Increase_enemy.h"
#include "./Cell/Object/Character/Enemy/Reproduce_enemy/Reproduce_enemy.h"
#include "./Cell/Object/Pathless/Pathless.h"

//#include <SFML/Graphics.hpp> //https://www.sfml-dev.org/tutorials/2.5/start-linux.php - про локальную установку SFML

class Game: public IObserver{
    Field* field;
    Field_view* field_view;
    Player* player;
    vector<Enemy*> enemies;
    vector<Equipment*> equipment;
    vector<Pathless*> pathless;
    Enter* enter;
    Exit* exit;
    Mover* mover;
public:
    Game(int count_enemies,int count_equip,int count_pathless,Field::Size size = Field::SMALL);
    void start_game();
    void create_enter();
    void create_exit();
    void create_player(pair<int, int> coord_enter);
    void create_enemyes(int count);
    void add_enemy(Enemy::Type_enemy type);
    void remove_enemy(Enemy &enemy);
    void create_equipments(int count);
    void add_equipments(Equipment::Type_equip type);
    void create_pathless(int count);
    void update(Commands command, IObservable &entity) override;
    ~Game();
};


#endif //MAIN_CPP_GAME_H
