#ifndef __ITEMS_H__
#define __ITEMS_H__

#include <array>
#include <memory>

#include "randomgenerator.hpp"


class MeleeItem
{
  public:
  MeleeItem( const int hammer, const int straightSword, const int greatSword, const int mace);
  const int getMeleeItem( const int randomMeleeItem ) const;
  const int getMeleeDamage() const;

  private:
  const int hammer__ = 2;
  const int straightSword__ = 4;
  const int greatSword__ = 6;
  const int mace__ = 3;

  std::array<std::unique_ptr<int>, 4> meleeItems;
  std::array<std::unique_ptr<int>, 4> storeMeleeItems();
};

typedef struct RangeItem
{
  int bow = 4;
  int flintlock = 5;
  int blunderbuss = 10;
  int musket = 6;
} Range;

typedef struct PotionItem
{
  int potion_of_healing = 65;
  int potion_of_steel = 10;
  int potion_of_might = 5;
  int potion_of_agility = 2;
} Potion;

typedef struct ArmorItem
{
  int leather_armor = 3;
  int chain_armor = 6;
  int bronze_armor = 9;
  int steel_armor = 12;
} Armor;

typedef struct ShieldItem
{
  int old_shield = 2;
  int wood_shield = 4;
  int bronze_shield = 6;
  int steel_shield = 8;
} Shield;

class UseItem
{
  public:
  void attackAction();
  void aidAction();
  void equipArmor();

  private:
  int randomItemSelector();
};

#endif
