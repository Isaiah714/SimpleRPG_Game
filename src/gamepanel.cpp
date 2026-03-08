#include <array>

#include "gamepanel.hpp"
#include "gameloop.hpp"
#include "enemies.hpp"

void gamePanel() 
{
  GameDialog log;
  std::string currentStage = "Menu";
  if( currentStage == "Menu" )
  {
    std::cout << "\033[2J\033[1;1H";
    animation("../ASCII_Frames/Menu/Title.txt", log);
    char input{};
    std::cout << "\n\t\t    Start Game?\n";
    std::cin >> input;
    if( input != ' ' ) { currentStage = "Items"; }
  }
  if( currentStage == "Items" )
  {
    std::cout << "\033[2J\033[1;1H";
    givePlayerSetOfItems( log );
    char input{};
    std::cout << "Enter any character to continue...";
    std::cin >> input;
    if( input != ' ' ) { currentStage = "Stage 1"; }
  }
  if( currentStage == "Stage 1" )
  {
    log.isEnemyTurn = true;
    spawnEnemy<Plains>( currentStage, log );
    animation("../ASCII_Frames/Plains/Slime_Encounter.txt", log);
  }
}

void givePlayerSetOfItems( GameDialog & dialog )
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

  dialog.printInventory = std::make_unique<Inventory>(playerInventory);
}

template<typename T>
void spawnEnemy( const std::string & stage, GameDialog & dialog )
{
  Enemy obj;
  obj.getEnemy<T>( stage );
  dialog.printEnemy = std::make_unique<Enemy>( std::move(obj) );
}

void animation( const std::string & filePath, GameDialog & dialog )
{
  GameLoop stream( filePath );
  stream.setDialog( dialog );
  std::cout << stream;
}