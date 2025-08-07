#ifndef __ITEMS_H__
#define __ITEMS_H__

#include "randomgenerator.hpp"

#include <map>

enum WeaponDamage
{
  hammer = 2,
  straightSword = 4,
  greatSword = 6,
  mace = 4,
  bow = 4,
  flintLock = 5,
  blunderBuss = 10,
  musket = 6
};


class WeaponItem : public Random
{
  public:
  WeaponItem();
  const std::pair<std::string, int> getWeaponItem();
  const int getWeaponDamage() const;
  std::map<std::string, int> allWeaponItems;
};

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
