#ifndef __ITEMS_H__
#define __ITEMS_H__

#include <map>
#include <random>
#include <iostream>
#include <vector>

//////////////////////////////RANDOM//////////////////////////////
class Random
{
  public:
  Random();
  Random( std::string item, std::vector<std::string> allItemName );

  private:
  std::string item__;
  std::vector<std::string> allItemName__;

  const int randomNumberGenerator( const int & maxRange );
  std::string getSelectedItem( const int & selectedItem );

  protected:
  template<typename ItemClass>
  std::string randomItemSelector( const ItemClass object );
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
  const std::pair<std::string, int> getWeaponItem();
  const int getWeaponDamage() const;
  std::map<std::string, int> allWeaponItems;
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
  std::map<std::string, int> allPotionItems;
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
  std::map<std::string, int> allArmorItems;
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
  std::map<std::string, int> allShieldItems;
};
//////////////////////////////////////////////////////////////////

#endif
