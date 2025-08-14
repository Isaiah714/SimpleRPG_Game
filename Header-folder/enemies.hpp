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
  void getEnemy( const std::string & stage );
  
  const std::string getName();
  const int getHealth();
  const int getAttack();
  const int getCriticalAttack();
  const int getSpecialAttack();
  
  private:
  std::string enemyName__;
  int enemyHealth__;
  int enemyAttack__; 
  int enemyCritAttack__;
  int enemySpecAttack__;


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
  Plains();
  Plains( const std::string enemyName, int health, int attack );
  std::string getName();
  const int getHealth();
  const int getAttack();
  const int getCriticalAttack();
  const int getSpecialAttack();

  Plains getPlainsEnemy( const std::string & stage );

  private:
  const std::string name__;
  int health__;
  int attack__;

  //std::vector<Plains> allPlainEnemies__;
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
  Forest();
  Forest( const std::string enemyName, int health, int attack );
  const std::string getName() const;
  const int getHealth();
  const int getAttack();
  const int getCriticalAttack();
  const int getSpecialAttack();

  private:
  const std::string enemyName__;
  int health__;
  int attack__;
};

enum CaveEnemyAttributes
{
  giantSpiderHealth = 100,
  giantSpiderAttack = 50,
  fleshRockHealth = 150,
  fleshRockAttack = 75,
  isolatedWizardHealth = 180,
  isolatedWizardAttack = 95,
  giantBloodWormHealth = 250,
  giantBloodWormAttack = 120
};

class Cave : public Enemy
{
  public:
  Cave();
  Cave( const std::string enemyName, int health, int attack );
  const std::string getName() const;
  const int getHealth();
  const int getAttack();
  const int getCriticalAttack();
  const int getSpecialAttack();

  private:
  const std::string enemyName__;
  int health__;
  int attack__;
};

enum ShoreEnemyAttributes
{
  graftedSoldierHealth = 300,
  graftedSoldierAttack = 180,
  darkWitchHealth = 400,
  darkWitchAttack = 225,
  steelKnightHealth = 600,
  steelKnightAttack = 350,
  primeGriffimHealth = 800,
  primeGriffimAttack = 500
};

class Shore : public Enemy
{
  public:
  Shore();
  Shore( const std::string enemyName, int health, int attack );
  const std::string getName() const;
  const int getHealth();
  const int getAttack();
  const int getCriticalAttack();
  const int getSpecialAttack();

  private:
  const std::string enemyName__;
  int health__;
  int attack__;
};

#endif
