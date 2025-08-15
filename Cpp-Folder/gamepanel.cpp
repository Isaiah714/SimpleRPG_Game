#include "ASCII_animation.hpp"
#include "gamepanel.hpp"

GamePanel::GamePanel()
{
  currentStage__ = "Stage 1";
  if( currentStage__ == "Stage 1" )
  {
    //animation("../ASCII-Frames/Plains/Slime_Encounter.txt");
    givePlayerSetOfItems();
    spawnEnemy<Plains>( currentStage__ );
  }

  

}

void GamePanel::animation( const std::string & filepath )
{
  Frame animateScreen{ filepath };
  std::cout << animateScreen;
}

void GamePanel::givePlayerSetOfItems() 
{
  if( !playersInventory__.empty() ) { playersInventory__.clear(); }

  WeaponItem wep;
  // Need to see the key to access the items status so it can be used in the combatPlayer function...
  auto showWep = std::make_pair( wep.getWeaponItem().first, wep.getWeaponItem().second );
  playersInventory__.insert( wep.getWeaponItem() );

  PotionItem pot;
  playersInventory__.insert( pot.getPotionItem() );

  ArmorItem arm;
  playersInventory__.insert( arm.getArmorItem() );

  ShieldItem shi;
  playersInventory__.insert( shi.getShieldItem() );

  std::cout << "Your inventory consist of...\n\n";
  for( const auto & showInventory : playersInventory__ )
  {
    std::cout << showInventory.first
              << "\nThe stat is "
              << showInventory.second
              << "\n\n";
  }
}

template<typename T>
void GamePanel::spawnEnemy( const std::string & stage )
{
  getEnemy<T>( stage );

  std::cout << "#################################################\n\n";

  std::cout << "You have encountered a " << getName()
            << "\n\nIt has " << getHealth() << " health points"
            << "\n\nIts attack deals " << getAttack() << " damage"
            << "\n\nIts critical attack deals " << getCriticalAttack()
            << " damage"
            << "\n\nIts special attack is " << getSpecialAttack()
            << " points\n";
}

void GamePanel::playercombat()
{
  
}