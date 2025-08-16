#include "items.hpp"

const int Random::randomNumberGenerator( const int & maxRange )
{
  std::random_device rdm;
  std::mt19937 gen(rdm());
  std::uniform_int_distribution<> distrib(0, maxRange);

  return distrib( gen );
}

std::string Random::getSelectedItem( const int & selectedItem )
{
  const std::string gotSelectedItem = allItemName__.at( selectedItem );
  return gotSelectedItem;
}

template<typename ItemClass>
std::string Random::randomItemSelector( const ItemClass object )
{
  if constexpr ( std::is_same<ItemClass, WeaponItem>::value )
  {
    allItemName__ = { "Hammer",
                      "Straight Sword",
                      "Great Sword",
                      "Mace",
                      "Bow",
                      "Flintlock",
                      "Blunderbuss",
                      "Musket" };
    int maxRange = allItemName__.size() - 1;
    int itemSelected = randomNumberGenerator( maxRange );
    item__ = getSelectedItem( itemSelected );
    allItemName__.clear();
    return item__;
  }
  if constexpr ( std::is_same<ItemClass, PotionItem>::value )
  {
    allItemName__ = { "Potion of Healing",
                      "Potion of Steel",
                      "Potion of Might",
                      "Potion of Agility" };
    int maxRange = allItemName__.size() - 1;
    int itemSelected = randomNumberGenerator( maxRange );
    item__ = getSelectedItem( itemSelected );
    allItemName__.clear();
    return item__;
  }
  if constexpr ( std::is_same<ItemClass, ArmorItem>::value )
  {
    allItemName__ = { "Leather Armor", 
                      "Chain Armor",
                      "Bronze Armor",
                      "Steel Armor" };
    int maxRange = allItemName__.size() - 1;
    int itemSelected = randomNumberGenerator( maxRange );
    item__ = getSelectedItem( itemSelected );
    allItemName__.clear();
    return item__;
  }
  if constexpr( std::is_same<ItemClass, ShieldItem>::value )
  {
    allItemName__ = { "Old Shield",
                      "Wood Shield",
                      "Bronze Shield",
                      "Steel Shield" };
    int maxRange = allItemName__.size() - 1;
    int itemSelected = randomNumberGenerator( maxRange );
    item__ = getSelectedItem( itemSelected );
    allItemName__.clear();
    return item__;
  }
  else
  {
    std::cout << "unsupported type\n";
  }
}

WeaponItem::WeaponItem()
{
  allWeaponItems__ = { { "Hammer",         WeaponDamage::hammer         },
                       { "Straight Sword", WeaponDamage::straightSword  },
                       { "Great Sword",    WeaponDamage::greatSword     },
                       { "Mace",           WeaponDamage::mace           },
                       { "Bow",            WeaponDamage::bow            },
                       { "Flintlock",      WeaponDamage::flintLock      },
                       { "Blunderbuss",    WeaponDamage::blunderBuss    },
                       { "Musket",         WeaponDamage::musket         } };
}

void WeaponItem::getWeaponItem()
{
  std::string randomWeaponItem = randomItemSelector( *this );
  auto getDamage = allWeaponItems__.find( randomWeaponItem );
  weaponName__ = randomWeaponItem;
  weaponDamage__ = getDamage->second;
  
  return;
}

const std::string WeaponItem::getWeaponName()
{
  return weaponName__;
}

const int WeaponItem::getWeaponDamage()
{
  return weaponDamage__;
}

PotionItem::PotionItem()
{
  allPotionItems__ = { { "Potion of Healing", PotionStatus::potionOfHealing },
                       { "Potion of Steel"  , PotionStatus::potionOfSteel   },
                       { "Potion of Might"  , PotionStatus::potionOfMight   }, 
                       { "Potion of Agility", PotionStatus::potionOfAgility } };
}

const std::pair<std::string, int> PotionItem::getPotionItem()
{
  std::string randomPotionItem = randomItemSelector( *this );
  auto getPotionStatus = allPotionItems__.find( randomPotionItem );
  std::pair<std::string, int> chosenPotionItem = std::make_pair( randomPotionItem, getPotionStatus->second );

  return chosenPotionItem;
}

ArmorItem::ArmorItem()
{
  allArmorItems__ = { { "Leather Armor", ArmorDefense::leatherArmor },
                      { "Chain Armor"  , ArmorDefense::chainArmor   },
                      { "Bronze Armor" , ArmorDefense::bronzeArmor  },
                      { "Steel Armor"  , ArmorDefense::steelArmor   } };
}

const std::pair<std::string, int> ArmorItem::getArmorItem()
{
  std::string randomArmorItem = randomItemSelector( *this );
  auto getArmorDefense = allArmorItems__.find( randomArmorItem );
  std::pair<std::string, int> chosenArmorItem = std::make_pair( randomArmorItem, getArmorDefense->second );

  return chosenArmorItem;
}

ShieldItem::ShieldItem()
{
  allShieldItems__ = { { "Old Shield",  ShieldDamageNegation::oldShield      }, 
                       { "Wood Shield", ShieldDamageNegation::woodShield     },
                       { "Bronze Shield", ShieldDamageNegation::bronzeShield },
                       { "Steel Shield", ShieldDamageNegation::steelShield   } };
}

const std::pair<std::string, int> ShieldItem::getShieldItem()
{
  std::string randomShieldItem = randomItemSelector( *this );
  auto getShieldDamageNegationStat = allShieldItems__.find( randomShieldItem );
  std::pair<std::string, int> chosenShieldItem = std::make_pair( randomShieldItem, getShieldDamageNegationStat->second );

  return chosenShieldItem;
}
