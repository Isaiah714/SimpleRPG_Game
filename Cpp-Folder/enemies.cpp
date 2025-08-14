#include "enemies.hpp"

Enemy::Enemy() {}

template<typename T> 
std::vector<T> Enemy::collectStageEnemies( const std::string & stage )
{
  std::vector<T> allEnemies = {};
  if constexpr ( std::is_same<T, Plains>::value )
  {
    if( stage == "Stage 1" )
    {
      std::vector<std::string> allNames = { "Green Slime", "Tall Slime", "Pile of Dirt", "Butter Cup" };
      for( int i = 0; i < allNames.size(); ++i )
      {
        if( allNames.at( i ) == "Green Slime" )
        {
          Plains greenSlime{ allNames.at( i ), PlainEnemyAttributes::slimeHealth, PlainEnemyAttributes::slimeAttack };
          allEnemies.push_back( greenSlime );
        }
        if( allNames.at( i ) == "Tall Slime" )
        {
          Plains tallSlime{ allNames.at( i ), PlainEnemyAttributes::tallSlimeHealth, PlainEnemyAttributes::tallSlimeAttack };
          allEnemies.push_back( tallSlime );
        }
        if( allNames.at( i ) == "Pile of Dirt" )
        {
          Plains pileOfDirt{ allNames.at( i ), PlainEnemyAttributes::pileOfDirtHealth, PlainEnemyAttributes::pileOfDirtAttack };
          allEnemies.push_back( pileOfDirt );
        }
        if( allNames.at( i ) == "Butter Cup" )
        {
          Plains butterCup{ allNames.at( i ), PlainEnemyAttributes::butterCupHealth, PlainEnemyAttributes::butterCupAttack };
          allEnemies.push_back( butterCup );
        }
      }
      return allEnemies;           
    }
  }
  if constexpr ( std::is_same<T, Forest>::value )
  {
    if( stage == "Stage 2" )
    {
      std::vector<std::string> allNames = { "Purple Zombie", "Shiny Skeleton", "Wondering Tree", "Lost Gnome" };
      for ( int i = 0; i < allNames.size(); ++i )
      {
        if( allNames.at( i ) == "Purple Zombie" )
        {
          Forest zombie{ allNames.at( i ), ForestEnemyAttributes::purpleZombieHealth, ForestEnemyAttributes::purpleZombieAttack };
          allEnemies.push_back( zombie );
        }
        if( allNames.at( i ) == "Shiny Skeleton" )
        {
          Forest skeleton{ allNames.at( i ), ForestEnemyAttributes::shinySkeletonHealth, ForestEnemyAttributes::shinySkeletonAttack };
          allEnemies.push_back( skeleton );
        }
        if( allNames.at( i ) == "Wondering Tree" )
        {
          Forest tree{ allNames.at( i ), ForestEnemyAttributes::wonderingTreeHealth, ForestEnemyAttributes::wonderingTreeAttack };
          allEnemies.push_back( tree );
        }
        if( allNames.at( i ) == "Lost Gnome" )
        {
          Forest gnome{ allNames.at( i ), ForestEnemyAttributes::lostGnomeHealth, ForestEnemyAttributes::lostGnomeAttack };
          allEnemies.push_back( gnome );
        }
      }
      return allEnemies;      
    }
  }
  else
  {
    std::vector<T> emptyEnemyContainer;
    std::cout << "Ran out of stages...\n";
    return emptyEnemyContainer;
  }
  return allEnemies; 
}

template<typename T>
void Enemy::getEnemy( const std::string & stage )
{
  std::vector<T> stageEnemies = {};
  if( stageEnemies.empty() ) { stageEnemies = collectStageEnemies<T>( stage ); }
  int maxRange = stageEnemies.size() - 1;
  int enemyIndex = randomNumberGenerator( maxRange );
  auto selectedEnemy = stageEnemies.at( enemyIndex );

  enemyName__ = selectedEnemy.getName();
  enemyHealth__ = selectedEnemy.getHealth();
  enemyAttack__ = selectedEnemy.getAttack();
  enemyCritAttack__ = selectedEnemy.getCriticalAttack();
  enemySpecAttack__ = selectedEnemy.getSpecialAttack();
}

const std::string Enemy::getName() { return enemyName__; }

const int Enemy::getHealth() { return enemyHealth__; }

const int Enemy::getAttack() { return enemyAttack__; }

const int Enemy::getCriticalAttack() { return enemyCritAttack__; }

// This function will only affect the players items
const int Enemy::getSpecialAttack() { return enemySpecAttack__; }

Plains::Plains() {}

Plains::Plains( const std::string enemyName, int health, int attack ) : name__{ enemyName }, health__{ health }, attack__{ attack }{}

std::string Plains::getName() { return name__; }

const int Plains::getHealth() { return health__; }

const int Plains::getAttack() { return attack__; }

const int Plains::getCriticalAttack() { return attack__ + 5; }

// This function will only affect the players items
const int Plains::getSpecialAttack() { return attack__ + 2; }

Forest::Forest() {}

Forest::Forest( const std::string enemyName, int health, int attack ) : enemyName__{ enemyName }, health__{ health }, attack__{ attack } {}

const std::string Forest::getName() const { return enemyName__; }

const int Forest::getHealth() { return health__; }

const int Forest::getAttack() { return attack__; }

const int Forest::getCriticalAttack() { return attack__ + 7; }

// This function will only affect the players items
const int Forest::getSpecialAttack() { return attack__ + 4; }

Cave::Cave() {}

Cave::Cave( std::string enemyName, int health, int attack ) : enemyName__{ enemyName }, health__{ health }, attack__{ attack } {}

const std::string Cave::getName() const { return enemyName__; }

const int Cave::getHealth() { return health__; }

const int Cave::getAttack() { return attack__; }

const int Cave::getCriticalAttack() { return attack__ + 11; }

const int Cave::getSpecialAttack() { return attack__ + 7; }


// The code below tells the compiler which version of methods to use at compile time
template void Enemy::getEnemy<Plains>( const std::string & stage );
template std::vector<Plains> Enemy::collectStageEnemies<Plains>( const std::string & stage );

template void Enemy::getEnemy<Forest>( const std::string & stage );
template std::vector<Forest> Enemy::collectStageEnemies<Forest>( const std::string & stage );

template void Enemy::getEnemy<Cave>( const std::string & stage );
template std::vector<Cave> Enemy::collectStageEnemies<Cave>( const std::string & stage );
