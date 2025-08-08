#include "ASCII_animation.hpp"
#include "items.hpp"


int main()
{
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

  return 0;
}
