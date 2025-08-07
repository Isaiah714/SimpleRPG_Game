#include "items.hpp"
#include "randomgenerator.hpp"

Random::Random() {}

Random::Random( std::string item, std::vector<std::string> allItemName ) : item__{ item }, allItemName__{ allItemName } {}

const int Random::randomNumberGenerator( const int & maxRange )
{
  std::random_device rdm;
  std::mt19937 gen(rdm());
  std::uniform_int_distribution<> distrib(0, maxRange);

  return distrib( gen );
}

std::string Random::getSelectedItem( const int & selectedItem )
{
  const std::string gotSelectedItem = allItemName__.at( selectedItem );
  return gotSelectedItem;
}

template<typename ItemClass>
std::string Random::randomItemSelector( const ItemClass object )
{
  int maxRange{};
  if constexpr ( std::is_same<ItemClass, WeaponItem>::value )
  {
    allItemName__ = { "Hammer",
                      "Straight Sword",
                      "Great Sword",
                      "Mace", "Bow",
                      "Flintlock",
                      "Blunderbuss",
                      "Musket" };
    maxRange = 8;
    int itemSelected = randomNumberGenerator( maxRange );
    item__ = getSelectedItem( itemSelected );
    return item__;
  }
  else
  {
    std::cout << "unsupported type\n";
  }
}
