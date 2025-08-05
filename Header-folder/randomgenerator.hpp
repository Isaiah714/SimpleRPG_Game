#ifndef __RANDOMGENERATOR__
#define __RANDOMGENERATOR__

#include <random>
#include <iostream>

class Random
{
  public:
  inline void randomItem()
  {
    // THIS IS TEMPORARY
    std::random_device rdm;
    std::mt19937 gen(rdm());
    std::uniform_int_distribution<> distrib(0, 3);


    std::cout << "The random number is: " << distrib(gen) << "\n" << std::endl;
  }

  private:
  const std::string item__;
  const int itemStat__;
};

#endif
