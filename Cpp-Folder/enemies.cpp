#include "enemies.hpp"

Enemy::Enemy() {}

template<typename T> 
std::vector<T> Enemy::collectStageEnemies( const std::string & stage )
{
  std::vector<T> allStageEnemies = {};
  if ( stage == "Stage 1" )
  {
    std::vector<std::string> allNames = { "Green Slime", "Tall Slime", "Pile of Dirt", "Butter Cup" };
    for( int i = 0; i < allNames.size(); ++i )
    {
      if( allNames.at( i ) == "Green Slime" )
      {
        Plains greenSlime{ allNames.at( i ), PlainEnemyAttributes::slimeHealth, PlainEnemyAttributes::slimeAttack };
        allStageEnemies.push_back( greenSlime );
      }
      if( allNames.at( i ) == "Tall Slime" )
      {
        Plains tallSlime{ allNames.at( i ), PlainEnemyAttributes::tallSlimeHealth, PlainEnemyAttributes::tallSlimeAttack };
        allStageEnemies.push_back( tallSlime );
      }
      if( allNames.at( i ) == "Pile of Dirt" )
      {
        Plains pileOfDirt{ allNames.at( i ), PlainEnemyAttributes::pileOfDirtHealth, PlainEnemyAttributes::pileOfDirtAttack };
      }
      if( allNames.at( i ) == "Butter Cup" )
      {
        Plains butterCup{ allNames.at( i ), PlainEnemyAttributes::butterCupHealth, PlainEnemyAttributes::butterCupAttack };
      }
    }
    return allStageEnemies;
  }
  if ( stage == "Stage 2" )
  {
    std::vector<std::string> allNames = { "Purple Zombie", "Shiny Skeleton", "WonderingTree", "LostGnome" };
    for( int i = 0; i < allNames.size(); ++i )
    {
      if( allNames.at( i ) == "Purple Zombie" )
      {
        Forest zombie{ allNames.at( i ), ForestEnemyAttributes::purpleZombieHealth, ForestEnemyAttributes::purpleZombieAttack };
      }
    }
  }
  else
  {
    allStageEnemies.clear();
    std::cout << "Ran out of stages...\n";
    return allStageEnemies;
  }
}

template<typename T>
T Enemy::getEnemy( const std::string & stage )
{
  std::vector<T> stageEnemies = {};
  if( stageEnemies.empty() ) { stageEnemies = collectStageEnemies( stage ); }
  int maxRange = stageEnemies.size() - 1;
  int enemyIndex = randomNumberGenerator( maxRange );
  auto selectedEnemy = stageEnemies.at( enemyIndex );

  return selectedEnemy;
}

Plains::Plains( const std::string enemyName, int health, int attack ) : enemyName__{ enemyName }, health__{ health }, attack__{ attack }{}

const std::string Plains::getName() const
{
  return enemyName__;
}

int Plains::getHealth()
{
  return health__;
}

int Plains::getAttack()
{
  return attack__;
}

int Plains::getcriticalAttack()
{
  return attack__ + 5;
}

// This function will only affect the players items
int Plains::getSpecialAttack()
{
  return attack__ + 2;
}

Forest::Forest( const std::string enemyName, int health, int attack ) : enemyName__{ enemyName }, health__{ health }, attack__{ attack } {}

const std::string Forest::getName() const
{
  return enemyName__;
}

int Forest::getHealth()
{
  return health__;
}

int Forest::getAttack()
{
  return attack__;
}

int Forest::getCriticalAttack()
{
  return attack__ + 7;
}

// This function will only affect the players items
int Forest::getSpecialAttack()
{
  return attack__ + 4;
}