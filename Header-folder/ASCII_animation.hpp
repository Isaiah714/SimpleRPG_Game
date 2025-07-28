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

class CollectFrames
{
  public:
  CollectFrames();
 ~CollectFrames() noexcept;

  std::string getCollectFrame();
  void setCollectFrame( const std::string  & oneFrame );

  private:
  std::string collectFrame__;
};

class Frame
{
  public:
  Frame();
  Frame( const std::string & filePath );
 ~Frame() noexcept;

  void displayFrame();

  private:
  const std::string filePath__;
  std::string loopCondition__;
  std::string frameBuffer__;

  std::vector<CollectFrames> allFrames__;
  std::string readFile();
};

#endif
