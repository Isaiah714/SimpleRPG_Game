#ifndef __RANDOMGENERATOR__
#define __RANDOMGENERATOR__

#include <random>
#include <iostream>
#include <vector>

class Random
{
  public:
  Random();
  Random( std::string item, std::vector<std::string> allItemName );

  private:
  std::string item__;
  std::vector<std::string> allItemName__;

  const int randomNumberGenerator( const int & maxRange );
  std::string getSelectedItem( const int & selectedItem );

  protected:
  template<typename ItemClass>
  std::string randomItemSelector( const ItemClass object );
};

#endif
