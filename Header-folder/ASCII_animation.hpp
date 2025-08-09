#ifndef __ASCII_ANIMATION_H__
#define __ASCII_ANIMATION_H__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#define FRAME_SIZE 21

class FrameContainer
{
  public:
  FrameContainer();

  void setFrame( const std::string & collectedFrame );

  std::string frame;
};

class Frame
{
  public:
  Frame();
  Frame( const std::string & filePath );

  friend std::ostream & operator<<( std::ostream & stream, Frame & frameBuffer);

  void testFunction();

  private:
  const std::string filePath__;
  std::string frameBuffer__;
  bool runLoop__;

  std::vector<FrameContainer> allFrames__;

  void readFile();
};

#endif
