#include "enemies.hpp"

Enemy::Enemy() {}

template<typename T> 
std::vector<T> Enemy::collectStageEnemies( const std::string & stage )
{
  if constexpr ( std::is_same<T, Plains>::value )
  {
    if( stage == "Stage 1" )
    {
      std::vector<T> allPlainEnemies = {};
      std::vector<std::string> allNames = { "Green Slime", "Tall Slime", "Pile of Dirt", "Butter Cup" };
      for( int i = 0; i < allNames.size(); ++i )
      {
        if( allNames.at( i ) == "Green Slime" )
        {
          Plains greenSlime{ allNames.at( i ), PlainEnemyAttributes::slimeHealth, PlainEnemyAttributes::slimeAttack };
          allPlainEnemies.push_back( greenSlime );
        }
        if( allNames.at( i ) == "Tall Slime" )
        {
          Plains tallSlime{ allNames.at( i ), PlainEnemyAttributes::tallSlimeHealth, PlainEnemyAttributes::tallSlimeAttack };
          allPlainEnemies.push_back( tallSlime );
        }
        if( allNames.at( i ) == "Pile of Dirt" )
        {
          Plains pileOfDirt{ allNames.at( i ), PlainEnemyAttributes::pileOfDirtHealth, PlainEnemyAttributes::pileOfDirtAttack };
          allPlainEnemies.push_back( pileOfDirt );
        }
        if( allNames.at( i ) == "Butter Cup" )
        {
          Plains butterCup{ allNames.at( i ), PlainEnemyAttributes::butterCupHealth, PlainEnemyAttributes::butterCupAttack };
          allPlainEnemies.push_back( butterCup );
        }
      }
      return allPlainEnemies;           
    }
  }
  if constexpr ( std::is_same<T, Forest>::value )
  {
    if( stage == "Stage 2" )
    {
      std::vector<T> allForestEnemies = {};
      std::vector<std::string> allNames = { "Purple Zombie", "Shiny Skeleton", "WonderingTree", "LostGnome" };
      for (int i = 0; i < allNames.size(); ++i )
      {
        if( allNames.at( i ) == "Purple Zombie" )
        {
          Forest zombie{ allNames.at( i ), ForestEnemyAttributes::purpleZombieHealth, ForestEnemyAttributes::purpleZombieAttack };
          allForestEnemies.push_back( zombie );
        }
        if( allNames.at( i ) == "Shiny Skeleton" )
        {
          Forest skeleton{ allNames.at( i ), ForestEnemyAttributes::shinySkeletonHealth, ForestEnemyAttributes::shinySkeletonAttack };
          allForestEnemies.push_back( skeleton );
        }
        if( allNames.at( i ) == "Wondering Tree" )
        {
          Forest tree{ allNames.at( i ), ForestEnemyAttributes::wonderingTreeHealth, ForestEnemyAttributes::wonderingTreeAttack };
          allForestEnemies.push_back( tree );
        }
        if( allNames.at( i ) == "Lost Gnome" )
        {
          Forest gnome{ allNames.at( i ), ForestEnemyAttributes::lostGnomeHealth, ForestEnemyAttributes::lostGnomeAttack };
          allForestEnemies.push_back( gnome );
        }
      }
      return allForestEnemies;      
    }
  }
  else
  {
    std::vector<T> emptyEnemyContainer;
    std::cout << "Ran out of stages...\n";
    return emptyEnemyContainer;
  }
}

template<typename T>
T Enemy::getEnemy( const std::string & stage )
{
  std::vector<T> stageEnemies = {};
  if( stageEnemies.empty() ) { stageEnemies = collectStageEnemies<T>( stage ); }
  int maxRange = stageEnemies.size() - 1;
  if( enemyIndex__ = 0 ) { enemyIndex__ = randomNumberGenerator( maxRange ); }
  auto selectedEnemy = stageEnemies.at( enemyIndex__ );

  return selectedEnemy;
}

Plains::Plains() {}

Plains::Plains( const std::string enemyName, int health, int attack ) : enemyName__{ enemyName }, health__{ health }, attack__{ attack }{}

std::string Plains::getName()
{
  return enemyName__;
}

Plains Plains::getPlainsEnemy( const std::string & stage )
{
  //this->attack__ = getEnemy<Plains>( stage ).getAttack();
  //this->health__ = getEnemy<Plains>( stage ).getHealth();
  //this->enemyName__ = getEnemy<Plains>( stage ).getName();
  return getEnemy<Plains>( stage );
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