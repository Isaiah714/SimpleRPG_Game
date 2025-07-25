#ifndef __ITEMS_H__
#define __ITEMS_H__

typedef struct MeleeItem
{
  int hammer = 2;
  int straight_sword = 4;
  int great_sword = 6;
  int mace = 3;
} Melee;

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

class UseItem
{
  public:
  void attackAction();
  void aidAction();
  void equipArmor();

  private:
  int randomItemSelector();
};

/* Create another class that would select a random item for the player
 * Then create the a small menu for the player to select of what to do        
 *  
 */

#endif
