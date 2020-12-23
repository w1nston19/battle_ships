cmake_minimum_required(VERSION 3.17)
project(battle_ships_proekt)

set(CMAKE_CXX_STANDARD 14)

include_directories(cmake-build-debug)

add_executable(battle_ships_proekt
        cmake-build-debug/battleShipsFunctions.h
        battleShips.cpp)
