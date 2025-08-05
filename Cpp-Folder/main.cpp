#include "ASCII_animation.hpp"


int main()
{
  Frame obj("../ASCII-Frames/Plains/Slime_Encounter.txt");
  std::cout << obj;
  //obj.collectFrame();
  
  return 0;
}
