#ifndef __GAMEPANEL__
#define __GAMEPANEL__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <array>
#include <chrono>
#include <thread>

#define FRAME_SIZE 21

inline std::array<std::pair<std::string, int>, 4> playerInventory;

void gamePanel();
void animation( const std::string & filePath );
void givePlayerSetOfItems();

template<typename T>
void spawnEnemy( const std::string & stage );

#endif

