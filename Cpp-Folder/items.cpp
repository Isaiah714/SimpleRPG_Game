#include "items.hpp"

WeaponItem::WeaponItem()
{
  allWeaponItems = { { "Hammer",         WeaponDamage::hammer         },
                     { "Straight Sword", WeaponDamage::straightSword  },
                     { "Great Sword",    WeaponDamage::greatSword     },
                     { "Mace",           WeaponDamage::mace           },
                     { "Bow",            WeaponDamage::bow            },
                     { "Flintlock",      WeaponDamage::flintLock      },
                     { "Blunderbuss",    WeaponDamage::blunderBuss    },
                     { "Musket",         WeaponDamage::musket         } };
}

const std::pair<std::string, int> WeaponItem::getWeaponItem()
{
  std::string randomWeaponItem = randomItemSelector( *this );
  auto getDamage = allWeaponItems.find( randomWeaponItem );
  std::pair<std::string, int> chosenWeaponItem = std::make_pair( randomWeaponItem, getDamage->second );
  
  return chosenWeaponItem;
}


