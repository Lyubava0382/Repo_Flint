#ifndef MAIN_CPP_MOVECHARACTER_H
#define MAIN_CPP_MOVECHARACTER_H

#include "../../Move/Mover.h"
#include "../../Field/Field.h"

class MoveCharacter : public Mediator {
private:
    Mover* moverPlayer;
    Field* field;

public:
    MoveCharacter(Field* field,Mover* moverPlayer) : moverPlayer(moverPlayer), field(field) {
        this->moverPlayer->set_mediator(this);
        this->field->set_mediator(this);
    }
    void Notify(ComponentMediator *sender,Direction dir) const override {
        if (event == "A") {
            std::cout << "Mediator reacts on A and triggers following operations:\n";
            this->component2_->DoC();
        }
        if (event == "D") {
            std::cout << "Mediator reacts on D and triggers following operations:\n";
            this->component1_->DoB();
            this->component2_->DoC();
        }
    }
};


#endif //MAIN_CPP_MOVECHARACTER_H
