#ifndef __GAMEPANEL__
#define __GAMEPANEL__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <array>
#include <chrono>
#include <thread>
#include <memory>

#include "enemies.hpp"

#define FRAME_SIZE 21

using Inventory = std::array<std::pair<std::string, int>, 4>;
//using EnemyAt = std::array<std::string, 5>;

inline std::array<std::pair<std::string, int>, 4> playerInventory;
inline std::array<std::string, 5> enemyAttributes;


struct GameDialog
{
  std::string statement;
  std::unique_ptr<Inventory> printInventory;
  std::unique_ptr<Enemy> printEnemy;
};

void gamePanel();
void animation( const std::string & filePath, GameDialog & dialog );
void givePlayerSetOfItems( GameDialog & dialog );

template<typename T>
void spawnEnemy( const std::string & stage, GameDialog & dialog );

#endif
