#ifndef __ITEMS_H__
#define __ITEMS_H__

#include <map>
#include <random>
#include <iostream>
#include <vector>

//////////////////////////////RANDOM//////////////////////////////
class Random
{
  private:
  std::string item__;
  std::vector<std::string> allItemName__;

  std::string getSelectedItem( const int & selectedItem );

  protected:
  template<typename ItemClass>
  std::string randomItemSelector( const ItemClass object );

  const int randomNumberGenerator( const int & maxRange );
};
//////////////////////////////////////////////////////////////////

//////////////////////////////WEAPON//////////////////////////////
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
  void getWeaponItem();
  const std::string getWeaponName();
  const int getWeaponDamage();

  private:
  std::map<std::string, int> allWeaponItems__;
  std::string weaponName__;
  int weaponDamage__;
};
//////////////////////////////////////////////////////////////////

//////////////////////////////POTION//////////////////////////////
enum PotionStatus
{
  potionOfHealing = 65,
  potionOfSteel = 10,
  potionOfMight = 5,
  potionOfAgility = 2
};

class PotionItem : public Random
{
  public:
  PotionItem();
  const std::pair<std::string, int> getPotionItem();

  private:
  std::map<std::string, int> allPotionItems__;
  std::string potionName__;
  int potionStat__;
};
//////////////////////////////////////////////////////////////////

//////////////////////////////ARMOR///////////////////////////////
enum ArmorDefense
{
  leatherArmor = 3,
  chainArmor = 6,
  bronzeArmor = 9,
  steelArmor = 12
};

class ArmorItem : public Random
{
  public:
  ArmorItem();
  const std::pair<std::string, int> getArmorItem();

  private:
  std::map<std::string, int> allArmorItems__;
  std::string armorName__;
  int armorDefense__;
};
//////////////////////////////////////////////////////////////////

//////////////////////////////SHIELD//////////////////////////////
enum ShieldDamageNegation
{
  oldShield = 2,
  woodShield = 4,
  bronzeShield = 6,
  steelShield = 8
};

class ShieldItem : public Random
{
  public:
  ShieldItem();
  const std::pair<std::string, int> getShieldItem();

  private:
  std::map<std::string, int> allShieldItems__;
  std::string shieldName__;
  int shieldNegation__;
};
//////////////////////////////////////////////////////////////////

#endif
