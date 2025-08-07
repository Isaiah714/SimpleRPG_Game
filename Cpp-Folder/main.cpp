#include "ASCII_animation.hpp"
#include "items.hpp"


int main()
{
  Frame obj("../ASCII-Frames/Plains/Slime_Encounter.txt");
  //std::cout << obj;
  
  WeaponItem item;
  std::pair<std::string, int> inventory = item.getWeaponItem();

  std::cout << "The weapon you got is the " << inventory.first << '\n';
  std::cout << "The " << inventory.first << " does " << inventory.second << " damage!\n";

  return 0;
}
