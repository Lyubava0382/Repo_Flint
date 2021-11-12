cmake_minimum_required(VERSION 3.20)
project(Game_OOP)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Game_OOP main.cpp Game/Cell/Cell.cpp Game/Cell/Cell.h
        Game/Field/Field.cpp Game/Field/Field.h Game/Iterator/Iterator.cpp
        Game/Iterator/Iterator.h Game/Cell/Object/Character/Enemy/Enemy.cpp
        Game/Cell/Object/Character/Enemy/Enemy.h
        Game/Cell/Object/Equipment/Equipment.cpp
        Game/Cell/Object/Equipment/Equipment.h
        Game/Cell/Object/Character/Player/Player.cpp
        Game/Cell/Object/Character/Player/Player.h
        Game/Cell/Object/Enter/Enter.cpp Game/Cell/Object/Enter/Enter.h
        Game/Cell/Object/Exit/Exit.cpp Game/Cell/Object/Exit/Exit.h
        Game/Cell/Object/Object.cpp Game/Cell/Object/Object.h
        Game/Cell/Object/Character/Enemy/Simple_enemy/Simple_enemy.cpp
        Game/Cell/Object/Character/Enemy/Simple_enemy/Simple_enemy.h
        Game/Cell/Object/Character/Enemy/Increase_enemy/Increase_enemy.cpp
        Game/Cell/Object/Character/Enemy/Increase_enemy/Increase_enemy.h
        Game/Cell/Object/Character/Enemy/Reproduce_enemy/Reproduce_enemy.cpp
        Game/Cell/Object/Character/Enemy/Reproduce_enemy/Reproduce_enemy.h
        Game/Cell/Object/Empty/Empty.cpp
        Game/Cell/Object/Empty/Empty.h
        Game/Cell/Object/Character/Character.cpp
        Game/Cell/Object/Character/Character.h
        Game/Game.cpp
        Game/Game.h
        Game/Cell/Object/Pathless/Pathless.cpp
        Game/Cell/Object/Pathless/Pathless.h
        Game/Field/Field_view/Field_view.cpp
        Game/Field/Field_view/Field_view.h
        Game/Cell/Object/Object_view.cpp
        Game/Cell/Object/Object_view.h
        Game/Move/Mover.cpp
        Game/Move/Mover.h
        #[[Game/Mediator/Mediator.cpp
        Game/Mediator/Mediator.h
        Game/Mediator/MoveCharacter/MoveCharacter.cpp
        Game/Mediator/MoveCharacter/MoveCharacter.h]]
        Game/Cell/Object/Equipment/Armor/Armor.cpp
        Game/Cell/Object/Equipment/Armor/Armor.h
        Game/Cell/Object/Equipment/Health/Health.cpp
        Game/Cell/Object/Equipment/Health/Health.h
        Game/Cell/Object/Equipment/Weapon/Weapon.cpp
        Game/Cell/Object/Equipment/Weapon/Weapon.h
        Game/Observer/IObserver.cpp Game/Observer/IObserver.h
        Game/Commands.h Game/Command/Command.cpp Game/Command/Command.h Game/Size_cell.h Game/Conditions.h Game/Logger/Logger.cpp Game/Logger/Logger.h)

target_link_libraries(Game_OOP sfml-graphics sfml-audio)
