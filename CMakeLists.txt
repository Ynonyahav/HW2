cmake_minimum_required(VERSION 3.25)
project(HW2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW2
        Card.cpp
        Card.h
        Mtmchkin.h
        Player.cpp
        Player.h
        test.cpp
        utilities.cpp
        utilities.h)
