#include "enemies.hpp"

Enemy::Enemy() {}

template<typename EnemyClass> 
std::vector<EnemyClass> Enemy::collectStageEnemies()
{
  std::vector<T> allStageEnemies = {};
  if constexpr ( std::is_same<EnemyClass, GreenSlime>::value )
  {
    GreenSlime gSlime;
    allStageEnemies.push_back( gSlime );
  }
  if constexpr ( std::is_same<EnemyClass, TallSlime>::value )
  {
    TallSlime tSlime;
    allStageEnemies.push_back( tSlime );
  }
  if constexpr( std::is_same<EnemyClass, PileOfDirt>::value )
  {
    PileOfDirt dirt;
    allStageEnemies.push_back( dirt );
  }
  if constexpr( std::is_same<EnemyClass, ButterCup>::value )
  {
    ButterCup butterCupFlower;
    allStageEnemies.push_back( butterCupFlower );
  }
  if constexpr( std::is_same<EnemyClass, PurpleZombie>::value )
  {
    PurpleZombie zombie;
    allStageEnemies.push_back( zombie );
  }
  if constexpr( std::is_same<EnemyClass, ShinySkeleton>::value )
  {
    ShinySkeleton skeleton;
    allStageEnemies.push_back( skeleton );
  }
  if constexpr ( std::is_same<EnemyClass, WonderingTree>::value )
  {
    WonderingTree tree;
    allStageEnemies.push_bakc( tree );
  }
  if constexpr ( std::is_same<EnemyClass, LostGnome>::value )
  {
    LostGnome gnome;
    allStageEnemies.push_back( gnome );
  }
}

template<typename T>
T Enemy::getEnemy()
{
  std::vector<T> stageEnemies = collectStageEnemies();
  int maxRange = stageEnemies.size() - 1;
  int enemyIndex = randomNumberGenerator( maxRange );
  auto selectedEnemy = stageEnemies.at( enemyIndex );

  return selectedEnemy;
}

// These enemy methods are temporary
GreenSlime::GreenSlime()
{
  health__ = 10;
  attack__ = 2;
}

int GreenSlime::criticalAttack()
{
  int critAttack = 2 + attack__;

  return critAttack;
}

int specialAttack()
{
  int specAttack = 3;
  
  return specAttack;
}