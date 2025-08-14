#include "ASCII_animation.hpp"
#include "enemies.hpp"


int main()
{
  //////////////////////////////////////////////////////////TEST PROGRAM//////////////////////////////////////////////////////////
  //Frame obj("../ASCII-Frames/Plains/Slime_Encounter.txt");
  //std::cout << obj;
  
  WeaponItem item;
  std::pair<std::string, int> inventory = item.getWeaponItem();
  std::cout << "The weapon you got is the " << inventory.first << "\nIt does " << inventory.second << " damage!\n\n";

  PotionItem potion;
  std::pair<std::string, int> pocket = potion.getPotionItem();
  std::cout << "You got the " << pocket.first << "\nThe stat is " << pocket.second << "!\n\n";

  ArmorItem armor;
  std::pair<std::string, int> body = armor.getArmorItem();
  std::cout << "You got " << body.first << "\nThe defense stat is " << body.second << "!\n\n";

  ShieldItem shield;
  std::pair<std::string, int> arm = shield.getShieldItem();
  std::cout << "You got the " << arm.first << "\nThe damage negation stat is " << arm.second << "!\n\n";

  Enemy p;
  const std::string stagep = "Stage 1";
  p.getEnemy<Plains>( stagep );
  std::cout << "Name: " << p.getName() << '\n' << "Health: " << p.getHealth() << '\n' << "Attack: " << p.getAttack() << '\n';
  std::cout << "Critical Attack: " << p.getCriticalAttack() << "\nSpecial Attack: " << p.getSpecialAttack() << "\n\n";

  Enemy f;
  const std::string stagef = "Stage 2";
  f.getEnemy<Forest>( stagef );
  std::cout << "Name: " << f.getName() << '\n' << "Health: " << f.getHealth() << '\n' << "Attack: " << f.getAttack() << '\n';
  std::cout << "Critical Attack: " << f.getCriticalAttack() << "\nSpecial Attack: " << f.getSpecialAttack() << "\n\n";

  Enemy c;
  const std::string stagec = "Stage 3";
  c.getEnemy<Cave>( stagec );
  std::cout << "Name: " << c.getName() << '\n' << "Health: " << c.getHealth() << '\n' << "Attack: " << c.getAttack() << '\n';
  std::cout << "Critical Attack: " << c.getCriticalAttack() << "\nSpecial Attack: " << c.getSpecialAttack() << "\n\n";

  Enemy s;
  const std::string stages = "Stage 4";
  s.getEnemy<Shore>( stages );
  std::cout << "Name: " << s.getName() << '\n' << "Health: " << s.getHealth() << '\n' << "Attack: " << s.getAttack() << '\n';
  std::cout << "Critical Attack: " << s.getCriticalAttack() << "\nSpecial Attack: " << s.getSpecialAttack() << "\n\n";

  
 
  return 0;
}
