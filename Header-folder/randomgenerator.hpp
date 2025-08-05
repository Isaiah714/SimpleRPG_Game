#ifndef __RANDOMGENERATOR__
#define __RANDOMGENERATOR__

#include <random>
#include <iostream>

class Random
{
  public:
  void randomItem();

  private:
  const std::string item__;
  const int itemStat__;
};

#endif
