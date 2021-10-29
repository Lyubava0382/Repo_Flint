cmake_minimum_required(VERSION 3.20)
project(Game_OOP)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Game_OOP main.cpp Game/Cell/Cell.cpp Game/Cell/Cell.h
        Game/Field/Field.cpp Game/Field/Field.h Game/Iterator/Iterator.cpp
        Game/Iterator/Iterator.h Game/Cell/Cell_interface.h Game/Cell/Object/Character/Enemy/Enemy.cpp Game/Cell/Object/Character/Enemy/Enemy.h Game/Cell/Object/Equipment/Equipment.cpp Game/Cell/Object/Equipment/Equipment.h Game/Cell/Object/Character/Player/Player.cpp Game/Cell/Object/Character/Player/Player.h Game/Cell/Object/Enter/Enter.cpp Game/Cell/Object/Enter/Enter.h Game/Cell/Object/Exit/Exit.cpp Game/Cell/Object/Exit/Exit.h Game/Cell/Object/Equipment/Equipment_interface.h Game/Cell/Object/Object.cpp Game/Cell/Object/Object.h Game/Cell/Object/Character/Enemy/Type1/Type1.cpp Game/Cell/Object/Character/Enemy/Type1/Type1.h Game/Cell/Object/Character/Enemy/Type2/Type2.cpp Game/Cell/Object/Character/Enemy/Type2/Type2.h Game/Cell/Object/Character/Enemy/Type3/Type3.cpp Game/Cell/Object/Character/Enemy/Type3/Type3.h Game/Cell/Object/Empty/Empty.cpp Game/Cell/Object/Empty/Empty.h Game/Cell/Object/Character/Character.cpp Game/Cell/Object/Character/Character.h Game/Game.cpp Game/Game.h)

target_link_libraries(Game_OOP sfml-graphics sfml-audio)
