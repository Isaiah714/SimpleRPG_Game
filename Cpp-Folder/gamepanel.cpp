#include "gamepanel.hpp"

GamePanel::GamePanel()
{
  currentStage__ = "Menu";
  if( currentStage__ == "Menu" )
  {
    std::cout << "\x1B[2J\x1B[H";
    animation("../ASCII-Frames/Menu/Title.txt");
    char input{};
    std::cout << "\n\t\t    Start Game?\n";
    std::cin >> input;
    if( input != ' ' ) { currentStage__ = "Items"; }
  }
  if( currentStage__ == "Items" )
  {
    std::cout << "\x1B[2J\x1B[H";
    givePlayerSetOfItems();
    char input{};
    std::cout << "Enter any character to continue...";
    std::cin >> input;
    if( input != ' ' ) { currentStage__ = "Stage 1"; }
  }
  if( currentStage__ == "Stage 1" )
  {
    animation("../ASCII-Frames/Plains/Slime_Encounter.txt");
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
  WeaponItem wep;
  wep.getWeaponItem();
  weapon__ = std::make_pair( wep.getWeaponName(), wep.getWeaponDamage() );

  PotionItem pot;
  pot.getPotionItem();
  potion__ = std::make_pair( pot.getPotionName(), pot.getPotionStat() );

  ArmorItem arm;
  arm.getArmorItem();
  armor__ = std::make_pair( arm.getArmorName(), arm.getArmorDefense() );

  ShieldItem shi;
  shi.getShieldItem();
  shield__ = std::make_pair( shi.getShieldName(), shi.getShieldNegation() );

  std::cout << "You got a "
            << weapon__.first << "\nIt does "
            << weapon__.second << " damage.\n\n"
            << "You got a "
            << potion__.first << "\nThe stat is "
            << potion__.second << "\n\n"
            << "You got "
            << armor__.first << "\nIts defense stat is "
            << armor__.second << "\n\n"
            << "You got a "
            << shield__.first << "\nIt negates "
            << shield__.second << " damage\n\n";  
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
