#ifndef __RANDOMGENERATOR__
#define __RANDOMGENERATOR__

#include <random>
#include <iostream>
#include <vector>

#include "items.hpp"

class Random
{
  public:
  Random();
  
  template<typename ItemClass>
  std::string & randomItemSelector( ItemClass object );

  private:
  const std::string item__;
  const int itemStat__;
  std::vector<std::string> itemName__;

  const int randomNumberGenerator( const int & maxRange );
  std::string getSelectedItem( const int & selectedItem,
                               const std::vector<std::string> & itemName );
};

#endif
