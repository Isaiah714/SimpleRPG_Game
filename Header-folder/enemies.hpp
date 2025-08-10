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
  T getEnemy( T stage );

  protected:
  template<typename T>
  std::vector<T> collectStageEnemies( const T & stage );

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
