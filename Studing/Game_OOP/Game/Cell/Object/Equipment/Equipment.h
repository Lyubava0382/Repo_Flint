#ifndef MAIN_CPP_EQUIPMENT_H
#define MAIN_CPP_EQUIPMENT_H

#include "../Object.h"
#define COUNT_OF_KIND_EQUIP 3

class Equipment: public Object{
protected:
    int state[COUNT_OF_KIND_EQUIP];
    Conditions type;
    void interact(Object *&entity) override {};
    void take_equip(Object *equip) override{};
    int get_protection() {return 0;};
    int get_health() {return 0;};
    int get_attack() override{return 0;};
    void set_attack(int attack) override{};
    void set_protection(int protection) override{};
    void set_health(int health) override{};
    void addObserver(IObserver* o) override{};
    void removeObserver(IObserver* o) override{};
    void notify(Commands dir) override{};
    void move(Commands dir) override{};
public:
    enum Type_equip{WEAPON, ARMOR, HEALTH};
    Conditions get_type() override{return this->type;};
    int* get_state();
    virtual Type_equip get_type_equip();
protected:
    Type_equip type_equip;
};


#endif //MAIN_CPP_EQUIPMENT_H
