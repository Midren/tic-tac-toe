cmake_minimum_required(VERSION 3.10)
project(tic_tac_toe)

set(CMAKE_CXX_STANDARD 11)

add_executable(tic_tac_toe main.cpp players.cpp field.cpp game.cpp game.h players.h field.h)