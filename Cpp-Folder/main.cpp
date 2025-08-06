#include "ASCII_animation.hpp"
#include "items.hpp"


int main()
{
  Frame obj("../ASCII-Frames/Plains/Slime_Encounter.txt");
  //std::cout << obj;
  
  WeaponItem item;

  item.getWeaponItem( 3 );

  return 0;
}
