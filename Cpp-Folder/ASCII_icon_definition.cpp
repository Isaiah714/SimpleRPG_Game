#include <iostream>

#include "ASCII_icons.h"

void playerIcon() {
	std::cout << "  O" << "\n"
			  << " /|\\" << "\n"
			  << " / \\" << std::endl;
}

void slime() {
	std::cout << "   ________" << "\n"
			  << "  |        |" << "\n"
			  << " |          |" << "\n"
		      << " ------------" << std::endl;


}

void zombie() {
	std::cout << "   0" << "\n"
			  << " ~~|" << "\n"
			  << "  / \\" << std::endl;
}

void message() {
	std::cout << "        ___                                           ___" << "\n"
			  << "       |   |                                         |   |" << "\n"
			  << "       |   |                                         |   |" << "\n"
			  << " ------     ------                             ------     ------ " << "\n"
			  << "|                 | Do you have the Blessing? |                 |" << "\n"
			  << " ------     ------                             ------     ------ " << "\n"
			  << "       |   |                                         |   |" << "\n"
			  << "       |   |                                         |   |" << "\n"
			  << "       |   |                                         |   |" << "\n"
			  << "       |   |                                         |   |" << "\n"
			  << "        ---                                           ---" << std::endl;

	std::cout << "Fight your way through different stages while obtaining " 
			  << "various items to help you along your journey to survive " 
			  << "until the end, good luck!" << std::endl;
}
