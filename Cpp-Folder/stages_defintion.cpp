#include <iostream>

#include "ASCII_icons.h"
#include "stages.h"

bool plains() {
	slime();
	
	return true;
}

bool forest() {
	zombie();
	return true;
}

bool cave() {
	std::cout << "cave holds true." << std::endl;
	return true;
}

bool the_shore() {
	std::cout << "the shore holds true." << std::endl;
	return true;
}
