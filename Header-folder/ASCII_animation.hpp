#ifndef __ASCII_ANIMATION_H__
#define __ASCII_ANIMATION_H__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#define TEXT_LINES_PLAINS 21

class FrameContainer
{
  public:
  FrameContainer();
 ~FrameContainer() noexcept;

  void setFrame( const std::string & collectedFrame );

  std::string frame;
};

class Frame
{
  public:
  Frame();
  Frame( const std::string & filePath );
 ~Frame() noexcept;

  friend std::ostream & operator<<( std::ostream & stream, Frame & frameBuffer);

  private:
  const std::string filePath__;
  std::string frameBuffer__;
  bool runLoop__;
    std::streampos framePoint__;

  std::vector<FrameContainer> allFrames__;

  std::string readFile();
  void collectFrame();
};

#endif
