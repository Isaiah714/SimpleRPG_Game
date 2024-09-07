#ifndef STAGES_H
#define STAGES_H

bool plains();

bool forest();

bool cave();

bool the_shore();

#include <vector>
#include <string>

class enemy_Type {
public:
	std::vector<std::string> slimeType{ "Green", "Yellow", "Red", "Black" };

	std::vector<std::string> zombieType{ "Regular", "Tall", "Buff", "Metal" };

	std::vector <std::string> spiderType{ "Whip Scorpion" , "Cave Spider", "Centipede" , "Black Widow" };

	std::vector<std::string> pirateType{ "Pirate Swordsman", "Pirate Gunslinger", "Pirate Marksman", "Pirate Artillery" };

};


class enemy : public enemy_Type {
public:
	enemy(const std::string& enemy) : enemy_(enemy) {};

private:
	std::string enemy_;
};

#endif
