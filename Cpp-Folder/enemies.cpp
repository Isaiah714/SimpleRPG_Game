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
  if constexpr ( std::is_same<T, Cave>::value )
  {
    if( stage == "Stage 3" )
    {
      std::vector<std::string> allNames = { "Giant Spider", "Flesh Rock", "Isolated Wizard", "Giant Blood Worm" };
      for( int i = 0; i < allNames.size(); ++i)
      {
        if( allNames.at( i ) == "Giant Spider" )
        {
          Cave spider{ allNames.at( i ), CaveEnemyAttributes::giantSpiderHealth, CaveEnemyAttributes::giantSpiderAttack };
          allEnemies.push_back( spider );
        }
        if( allNames.at( i ) == "Flesh Rock" )
        {
          Cave rock{ allNames.at( i ), CaveEnemyAttributes::fleshRockHealth, CaveEnemyAttributes::fleshRockAttack };
          allEnemies.push_back( rock );
        }
        if( allNames.at( i ) == "Isolated Wizard" )
        {
          Cave wizard{ allNames.at( i ), CaveEnemyAttributes::isolatedWizardHealth, CaveEnemyAttributes::isolatedWizardAttack };
          allEnemies.push_back( wizard );
        }
        if( allNames.at( i ) == "Giant Blood Worm" )
        {
          Cave worm{ allNames.at( i ), CaveEnemyAttributes::giantBloodWormHealth, CaveEnemyAttributes::giantBloodWormAttack };
          allEnemies.push_back( worm );
        }
      }
      return allEnemies;
    }
  }
  if constexpr ( std::is_same<T, Shore>::value )
  {
    if( stage == "Stage 4" )
    {
      std::vector<std::string> allNames = { "Grafted Soldier", "Dark Witch", "Steel Knight", "Prime Griffis" };
      for( int i = 0; i < allNames.size(); ++i )
      {
        if( allNames.at( i ) == "Grafted Soldier" )
        {
          Shore soldier{ allNames.at( i ), ShoreEnemyAttributes::graftedSoldierHealth, ShoreEnemyAttributes::graftedSoldierAttack };
          allEnemies.push_back( soldier );
        }
        if( allNames.at( i ) == "Dark Witch" )
        {
          Shore witch{ allNames.at( i ), ShoreEnemyAttributes::darkWitchHealth, ShoreEnemyAttributes::darkWitchAttack };
          allEnemies.push_back( witch );
        }
        if( allNames.at( i ) == "Steel Knight" )
        {
          Shore knight{ allNames.at( i ), ShoreEnemyAttributes::steelKnightHealth, ShoreEnemyAttributes::steelKnightAttack };
          allEnemies.push_back( knight );
        }
        if( allNames.at( i ) == "Prime Griffis" )
        {
          Shore griffis{ allNames.at( i ), ShoreEnemyAttributes::primeGriffisHealth, ShoreEnemyAttributes::primeGriffisAttack };
          allEnemies.push_back( griffis );
        }
      }
      return allEnemies;
    }
  }
  else
  {
    allEnemies.clear();
    std::cout << "ERROR - Class type must correspond to the appropiate stage number!\n";
    std::cout << "Example - If the class type is Plains, currentStage__ MUST equal to 'Stage 1.'\n";
    return allEnemies;
  }
  // I put this duplicate code here since using class type 'Shore' incorreclty skips the else block.
  std::cout << "ERROR - Class type must correspond to the appropiate stage number!\n";
  std::cout << "Example - If the class type is Plains, currentStage__ MUST equal to 'Stage 1.'\n";
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

// This function will only affect the players items
const int Cave::getSpecialAttack() { return attack__ + 7; }

Shore::Shore() {}

Shore::Shore( const std::string enemyName, int health, int attack) : enemyName__{ enemyName }, health__{ health }, attack__{ attack } {}

const std::string Shore::getName() const { return enemyName__; }

const int Shore::getHealth() { return health__; }

const int Shore::getAttack() { return attack__; }

const int Shore::getCriticalAttack() { return attack__ + 20; }

// This function will only affect the players items
const int Shore::getSpecialAttack() { return attack__ + 12; }


// The code below tells the compiler which version template to use at compile time
template void Enemy::getEnemy<Plains>( const std::string & stage );
template std::vector<Plains> Enemy::collectStageEnemies<Plains>( const std::string & stage );

template void Enemy::getEnemy<Forest>( const std::string & stage );
template std::vector<Forest> Enemy::collectStageEnemies<Forest>( const std::string & stage );

template void Enemy::getEnemy<Cave>( const std::string & stage );
template std::vector<Cave> Enemy::collectStageEnemies<Cave>( const std::string & stage );

template void Enemy::getEnemy<Shore>( const std::string & stage );
template std::vector<Shore> Enemy::collectStageEnemies( const std::string & stage );
