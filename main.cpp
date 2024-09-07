#include <iostream>
#include <vector>

#include "stages.h"
#include "items.h"
#include "ASCII_icons.h"

int main(int argc, char* argv[]) {
	
	std::vector<std::string> enemyEncounter = {"slime", "zombie", "insect", "pirate"};
	int stageNumber = 0;
	char input = 'T';
	message();

	while (!(input == 'N' || input == 'n' || stageNumber == 5)) {
		std::cout << "Press Y/y to continue or press N/n to quit." << std::endl;
		std::cin >> input;
		if (input == 'Y' || input == 'y') {
			switch (stageNumber) {
			case 0:
				std::cout << "You are in stage 1 THE PLAINS\n" << std::endl;
				random_system();
				plains();
				break;

			case 1:
				std::cout << "You are in stage 2 THE FOREST\n" << std::endl;
				random_system();
				forest();
				break;

			case 2:
				std::cout << "You are in stage 3 THE CAVE\n" << std::endl;
				random_system();
				break;

			case 3:
				std::cout << "You are in stage 4 THE SHORE\n" << std::endl;
				random_system();
				break;
			default:
				std::cout << "You have passed all the stages, congratulations!" << std::endl;
			}

			stageNumber += 1;
			
		}

	}

	std::cout << "The game has ended..." << std::endl;

	return 0;
}
