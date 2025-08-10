#ifndef __ENEMIES_H__
#define __ENEMIES_H__

#include <vector>
#include <string>

#include "items.hpp"

// IDEA - Have one class that takes care of enemy actions
// Then create structs to set enemy attributes and use those 
// attributes into classes that correspond to each enemy

class Enemy : Random
{
  public:
  Enemy();
  template<typename T>
  T getEnemy( const std::string & stage );

  private:
  template<typename T>
  std::vector<T> collectStageEnemies( const std::string & stage );

};

enum PlainEnemyAttributes
{
  slimeHealth = 10,
  slimeAttack = 2,
  tallSlimeHealth = 15,
  tallSlimeAttack = 6,
  pileOfDirtHealth = 20,
  pileOfDirtAttack = 9,
  butterCupHealth = 25,
  butterCupAttack = 12
};

class Plains : public Enemy
{
  public:
  Plains( const std::string enemyName, int health, int attack );
  const std::string getName() const;
  int getHealth();
  int getAttack();
  int getcriticalAttack();
  int getSpecialAttack();

  private:
  const std::string enemyName__;
  int health__;
  int attack__;

  std::vector<Plains> allPlainEnemies__;
};

enum ForestEnemyAttributes
{
  purpleZombieHealth = 35,
  purpleZombieAttack = 16,
  shinySkeletonHealth = 45,
  shinySkeletonAttack = 23,
  wonderingTreeHealth = 60,
  wonderingTreeAttack = 32,
  lostGnomeHealth = 25,
  lostGnomeAttack = 35
};

class Forest : public Enemy
{
  public:
  Forest( const std::string enemyName, int health, int attack );
  const std::string getName() const;
  int getHealth();
  int getAttack();
  int getCriticalAttack();
  int getSpecialAttack();

  private:
  const std::string enemyName__;
  int health__;
  int attack__;

  std::vector<Forest> allForestEnemies__;
};

class GreenSlime : public Enemy
{
  public:
  GreenSlime();
  int criticalAttack();
  int specialAttack();

  private:
  int health__;
  int attack__;
};

class TallSlime : public Enemy
{
  public:
  TallSlime();
  int criticalAttack();
  int specialAttack();

  private:
  int health__;
  int attack__;
};

class PileOfDirt : public Enemy
{
  public:
  PileOfDirt();
  int criticalAttack();
  int specialAttack();

  private:
  int health__;
  int attack__;
};

class ButterCup : public Enemy
{
  public:
  ButterCup();
  int criticalAttack();
  int specialAttack();

  private:
  int health__;
  int attack__;
};

class PurpleZombie : public Enemy
{
  public:
  PurpleZombie();
  int criticalAttack();
  int specialAttack();

  private:
  int health__;
  int attack__;
};

class ShinySkeleton : public Enemy
{
  public:
  ShinySkeleton();
  int criticalAttack();
  int specialAttack();

  private:
  int health__;
  int attack__;
};

class WonderingTree : public Enemy
{
  public:
  WonderingTree();
  int criticalAttack();
  int specialAttack();

  private:
  int health__;
  int attack__;
};

class LostGnome : public Enemy
{
  public:
  LostGnome();
  int criticalAttack();
  int specialAttack();

  private:
  int health__;
  int attack__;  
};

#endif
