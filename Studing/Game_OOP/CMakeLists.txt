cmake_minimum_required(VERSION 3.20)
project(Game_OOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game_OOP main.cpp ./Cell/Cell.cpp ./Cell/Cell.h ./Field/Field.cpp ./Field/Field.h ./Iterator/Iterator.cpp ./Iterator/Iterator.h Cell/Cell_interface.h)
