cmake_minimum_required(VERSION 3.28.3)

project(SimpleRPG_Game)

add_executable(play src/main.cpp
                    src/items.cpp
                    src/enemies.cpp
                    src/gamepanel.cpp
                    src/gameloop.cpp)

target_include_directories(play PRIVATE include)
target_link_libraries(play PRIVATE ncursesw)