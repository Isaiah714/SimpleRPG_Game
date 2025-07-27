cmake_minimum_required(VERSION 4.0.0)

project(SimpleRPG_Game)

add_executable(play Cpp-Folder/main.cpp Cpp-Folder/items.cpp Cpp-Folder/ASCII.cpp)

target_include_directories(play PRIVATE Header-folder)