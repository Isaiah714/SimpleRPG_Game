#include <random>
#include <iostream>

#include "items.hpp"

void random_system() {
    std::random_device rdm;
    std::mt19937 gen(rdm());
    std::uniform_int_distribution<> distrib(0, 3);


    std::cout << "The random number is: " << distrib(gen) << "\n" << std::endl;
}
