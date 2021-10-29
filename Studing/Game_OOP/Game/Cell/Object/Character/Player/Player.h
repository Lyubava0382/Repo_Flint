#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H

#include "../Character.h"

class Player: public Character{
    void foo() override{};
public:
    Player();
    void figth();
};


#endif //MAIN_CPP_PLAYER_H
