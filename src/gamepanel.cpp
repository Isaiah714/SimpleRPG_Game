#include <array>

#include "gamepanel.hpp"
#include "ASCII_animation.hpp"
#include "enemies.hpp"

void gamePanel() 
{
  std::string currentStage = "Menu";
  if( currentStage == "Menu" )
  {
    std::cout << "\x1B[2J\x1B[H";
    animation("../ASCII-Frames/Menu/Title.txt");
    char input{};
    std::cout << "\n\t\t    Start Game?\n";
    std::cin >> input;
    if( input != ' ' ) { currentStage = "Items"; }
  }
  if( currentStage == "Items" )
  {
    std::cout << "\x1B[2J\x1B[H";
    givePlayerSetOfItems();
    char input{};
    std::cout << "Enter any character to continue...";
    std::cin >> input;
    if( input != ' ' ) { currentStage = "Stage 1"; }
  }
  if( currentStage == "Stage 1" )
  {
    animation("../ASCII-Frames/Plains/Slime_Encounter.txt");
    spawnEnemy<Plains>( currentStage );
  }
}

void givePlayerSetOfItems()
{
  std::array<std::string, 4> allPotionNames = { "Potion of Healing",
                                                "Potion of Steel",
                                                "Potion of Might",
                                                "Potion of Agility" };
  WeaponItem wep;
  wep.getWeaponItem();
  std::pair<std::string, int> weapon = std::make_pair( wep.getWeaponName(), wep.getWeaponDamage() );
  playerInventory.at(0) = weapon;

  PotionItem pot;
  pot.getPotionItem();
  std::pair<std::string, int> potion = std::make_pair( pot.getPotionName(), pot.getPotionStat() );
  playerInventory.at(1) = potion;

  

  ArmorItem arm;
  arm.getArmorItem();
  std::pair<std::string, int> armor = std::make_pair( arm.getArmorName(), arm.getArmorDefense() );
  playerInventory.at(2) = armor;

  ShieldItem shi;
  shi.getShieldItem();
  std::pair<std::string, int> shield = std::make_pair( shi.getShieldName(), shi.getShieldNegation() );
  playerInventory.at(3) = shield;

  std::cout << "You got a "
            << weapon.first << "\nIt does "
            << weapon.second << " damage.\n\n"
            << "You got a "
            << potion.first << "\nThe stat is +"
            << potion.second << "\n\n"
            << "You got "
            << armor.first << "\nIts defense stat is "
            << armor.second << "\n\n"
            << "You got a "
            << shield.first << "\nIt negates "
            << shield.second << " damage\n\n";  
}

template<typename T>
void spawnEnemy( const std::string & stage )
{
  Enemy obj;
  obj.getEnemy<T>( stage );

  std::cout << "#################################################\n\n";

  std::cout << "You have encountered a " << obj.getName()
            << "\n\nIt has " << obj.getHealth() << " health points"
            << "\n\nIts attack deals " << obj.getAttack() << " damage"
            << "\n\nIts critical attack deals " << obj.getCriticalAttack()
            << " damage"
            << "\n\nIts special attack is " << obj.getSpecialAttack()
            << " points\n";
}

void animation( const std::string & filePath )
{
  Frame stream( filePath );
  std::cout << stream;
}