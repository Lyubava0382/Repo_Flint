//
// Created by danil on 23.10.2021.
//

#ifndef MAIN_CPP_CHARACTER_H
#define MAIN_CPP_CHARACTER_H

#include "../Object.h"

//Абстрактный класс для игрока и врага
class Character: public Object{
protected:
    std::vector<IObserver*> observers;
    Conditions type;
    int Attack;
    int Health;
    int Protection;
    int count_step;
public:
    void addObserver(IObserver* o) override;
    void removeObserver(IObserver* o) override;
    void notify(Commands dir) override;
    void move(Commands dir) override;
    Conditions get_type() override;
    int get_attack() override;
    int get_protection() override;
    int get_health() override;
    void set_attack(int attack) override;
    void set_protection(int protection) override;
    void set_health(int health) override;
    virtual void foo() = 0;


};


#endif //MAIN_CPP_CHARACTER_H
