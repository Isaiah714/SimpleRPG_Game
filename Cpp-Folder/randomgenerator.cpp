#include <randomgenerator.hpp>

const int Random::randomNumberGenerator( const int & maxRange )
{
  std::random_device rdm;
  std::mt19937 gen(rdm());
  std::uniform_int_distribution<> distrib(0, maxRange);

  return distrib( gen );
}

std::string Random::getSelectedItem( const int & selectedItem,
                                     const std::vector<std::string> & itemName )
{
  const std::string gotSelectedItem = itemName.at( selectedItem );
  return gotSelectedItem;
}

template<typename ItemClass>
std::string & Random::randomItemSelector( ItemClass object )
{
  int maxRange{};
  switch( ItemClass )
  {
    case WeaponItem:
    itemName__ = { "Hammer",
                   "Straight Sword",
                   "Great Sword",
                   "Mace", "Bow",
                   "Flintlock",
                   "Blunderbuss",
                   "Musket" };
    maxRange = 8;
    int itemSelected = randomNumberGenerator( maxRange );
    item__ = getSelectedItem( itemSelected, itemName__ );
    return item__;
    break;
  
    case PotionItem:
    break;
  
    case ArmorItem:
    break;
  
    case ShieldItem:
    break;
  
    default:
    std::cerr << "Something went wrong" << std::endl;
    break;
  }
}
