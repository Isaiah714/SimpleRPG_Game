#ifndef ITEMS_H
#define ITEMS_H

#include <vector>

class melee {
public:

	int hammer = 2;
	int straight_sword = 4;
	int great_sword = 6;
	int mace = 3;

	std::vector<int> mel_wep = { hammer, straight_sword, great_sword, mace };

};

class range {
public:

	int bow = 4;
	int flintlock = 5;
	int blunderbuss = 10;
	int musket = 6;

	std::vector<int> ran_wep = { bow, flintlock, blunderbuss, musket };

};

class aid {
public:

	int potion_of_healing = 65;
	int potion_of_steel = 10;
	int potion_of_might = 5;
	int potion_of_agility = 2;

	std::vector<int> pot_aid = { potion_of_healing, potion_of_steel, potion_of_might, potion_of_agility };
};

class armor {
public:

	int leather_armor = 3;
	int chain_armor = 6;
	int bronze_armor = 9;
	int steel_armor = 12;

	std::vector<int> arm_pro = { leather_armor, chain_armor, bronze_armor, steel_armor };
};

void random_system();

#endif
