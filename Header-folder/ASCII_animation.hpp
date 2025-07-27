#ifndef __ASCII_ANIMATION_H__
#define __ASCII_ANIMATION_H__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#define FRAME_LINES_PLAINS 21

class Frame
{
  public:
  Frame( const std::string & filePath );
 ~Frame() noexcept;
  
  std::string getFrame() const;
  std::string displayFrame();

 private:
 std::string frameBuffer__;
 const std::string filePath__;

 void readFile();

};

#endif
