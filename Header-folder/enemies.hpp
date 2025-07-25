#ifndef __Enemy__
#define __Enemy__

#include <array>
#include <string>

// IDEA - Have one class that takes care of enemy actions
// Then create structs to set enemy attributes and use those 
// attributes into classes that correspond to each enemy

class Enemy
{
  public:
  typedef struct GreenSlime
  {
    std::string name = "green slime";
    int health = 10;
    int attack = 2;

  } GSlime;

  typedef struct TallSlime
  {
    std::string name = "tall slime";
    int health = 12;
    int attack = 5;
  } TSlime;

  typedef struct PileOfDirt
  {
    std::string name = "pile of dirt";
    int health = 15;
    int attack = 7;
  } PDirt;

  typedef struct ButterCup
  {
    std::string name = "butter cup";
    int health = 18;
    int attack = 9;
  } BCup;

  typedef struct PurpleZombie
  {
    std::string name = "purple zombie";
    int health = 25;
    int attack = 15;
    int special_attack = 19;
    int defense = 5;
  } PZombie;

  typedef struct ShinySkeleton
  {
    std::string name = "shiny skeleton";
    int health = 22;
    int attack = 18;
    int special_attack = 23;
    int defense = 5;
  } SSkeleton;

  typedef struct WonderingTree
  {
    std::string name = "wondering tree";
    int health = 30;
    int attack = 20;
    int special_attack = 25;
    int defense = 10;
  } WTree;

  typedef struct LostGnome
  {
    std::string name = "lost gnome";
    int health = 15;
    int attack = 5;
    int special_attack = 35;
    int defense = 3;
  } LGnome;

  protected:
  std::array<Enemy, 4> plain_Enemy__;
  std::array<Enemy, 4> forest_Enemy__;
};

class EnemyAction : public Enemy
{
  public:
  EnemyAction();
 ~EnemyAction();

  private:
  Enemy * randomEnemy( std::array<std::string, 4> Enemy );
  
};

#endif
