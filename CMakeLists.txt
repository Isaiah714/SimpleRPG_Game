cmake_minimum_required(VERSION 3.28.3)

project(SimpleRPG_Game)

add_executable(play Cpp-Folder/main.cpp Cpp-Folder/items.cpp Cpp-Folder/ASCII_animation.cpp Cpp-Folder/enemies.cpp)

target_include_directories(play PRIVATE Header-folder)