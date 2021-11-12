#include "Player.h"

Player::Player(){
    type = PLAYER;
    Attack = 1;
    Health = 1;
    Protection = 1;
}

void Player::interact(Object *&entity) {
    switch (entity->get_type()) {
        case ENEMY:
            entity->set_health(entity->get_health() - this->Attack);
            std::cout << entity->get_health() << std::endl;
            if(entity->get_health() <= 0){
                dynamic_cast<Enemy*>(entity)->death();
                entity = new Empty();
            }
            break;
        case EQUIPMENT:
            this->take_equip(dynamic_cast<Equipment*>(entity));
            entity = new Empty();
            std::cout << "Attack: " << this->get_attack() <<
                      " Protection: " << this->get_protection() <<
                      " Health: " << this->get_health() << std::endl;
            break;
        case EXIT:
            this->exit();
    }
}

void Player::take_equip(Object *equip){
    equipment.push_back(dynamic_cast<Equipment*>(equip));
    this->Attack += dynamic_cast<Equipment*>(equip)->get_state()[Equipment::Type_equip::WEAPON];
    this->Protection += dynamic_cast<Equipment*>(equip)->get_state()[Equipment::Type_equip::ARMOR];
    this->Health += dynamic_cast<Equipment*>(equip)->get_state()[Equipment::Type_equip::HEALTH];
};

void Player::exit() {
    this->notify(EXIT_GAME);
}

/*void Player::figth(){

};*/
