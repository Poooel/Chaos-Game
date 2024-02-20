cmake_minimum_required(VERSION 3.28)
project(chaos_game)

set(CMAKE_CXX_STANDARD 23)

include_directories(include)

add_executable(chaos_game
        source/main.cpp
        source/Point.cpp
        source/ChaosGame.cpp
)
