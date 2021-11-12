//
// Created by danil on 09.11.2021.
//

#ifndef MAIN_CPP_COMMAND_H
#define MAIN_CPP_COMMAND_H

#include "../Commands.h"

class Command {
public:
    Commands step_left();
    Commands step_right();
    Commands step_top();
    Commands step_down();
    Commands any_step();
};


#endif //MAIN_CPP_COMMAND_H
