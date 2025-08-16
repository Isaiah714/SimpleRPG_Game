#ifndef __GAMEPANEL__
#define __GAMEPANEL__

#include "enemies.hpp"

class GamePanel : public Enemy
{
  public:
  GamePanel();

  private:
  std::map<std::string, int> playersInventory__;
  std::pair<std::string, int> weapon__;
  std::pair<std::string, int> potion___;
  std::pair<std::string, int> armor__;
  std::pair<std::string, int> shield__;
  std::string currentStage__;

  void animation( const std::string & filepath );
  void givePlayerSetOfItems();
  void playercombat();

  template<typename T>
  void spawnEnemy( const std::string & stage );
};

#endif