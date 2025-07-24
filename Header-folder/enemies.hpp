#ifndef __ENEMIES__
#define __ENEMIES__

#include <unordered_map>
#inlcude <string>

// IDEA - Have one class that takes care of enemy actions
// Then create structs to set enemy attributes and use those 
// attributes into classes that correspond to each enemy

class PlainEnemies
{
  public:
  void enemyAttack( std::unordered_map<std::string, int> enemy );

  private:
  std::unordered_map<std::string, int> plain_enemies__;

  void getDamage();
  void getName  ();
};

class CaveEnemies : PlainEnemies
{
  public:
  void enemyAttack( std::unorderd_map<std::string, int> enemy  );
  void enemyMagic ( std::unordered_map<std::string, int> enemy );

  private:
  std::unordered_map<std::string, int> cave_enemies__;

  void getDamage();
  void getName  ();
};

#endif
