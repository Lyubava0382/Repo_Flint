//
// Created by danil on 09.11.2021.
//

#include "Command.h"


Commands Command::step_left(){
    return LEFT_STEP;
}
Commands Command::step_right(){
    return RIGHT_STEP;
}
Commands Command::step_top(){
    return TOP_STEP;
}
Commands Command::step_down(){
    return DOWN_STEP;
}
Commands Command::any_step(){
    return ANY_STEP;
}