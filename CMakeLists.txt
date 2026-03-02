cmake_minimum_required(VERSION 3.28.3)

project(SimpleRPG_Game)

add_executable(play src/main.cpp
                    src/items.cpp
                    src/enemies.cpp
                    src/gamepanel.cpp
                    src/ASCII_animation.cpp)

target_include_directories(play PRIVATE include)