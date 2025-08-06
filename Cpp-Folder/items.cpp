#include <random>
#include <iostream>

#include "items.hpp"

WeaponItem::WeaponItem()
{
  allWeaponItems = { { "Hammer",         2  },
                     { "Straight Sword", 4  },
                     { "Great Sword",    6  },
                     { "Mace",           4  },
                     { "Bow",            4  },
                     { "Flintlock",      5  },
                     { "Blunderbuss",    10 },
                     { "Musket",         6  } };
}

const int * WeaponItem::getWeaponItem( const int & randomWeaponItem ) const
{
  //int * chosenWeaponItem = allWeaponItems.at( randomWeaponItem );

  //return chosenWeaponItem;

  return 0;
}