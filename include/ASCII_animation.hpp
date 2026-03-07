#ifndef __ASCII_ANIMATION_H__
#define __ASCII_ANIMATION_H__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#include "gamepanel.hpp"

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

  GameDialog * getDialog();
  void setDialog( GameDialog & dialog );

  friend std::ostream & operator<<( std::ostream & stream, Frame & frameBuffer);

  private:
  const std::string filePath__;
  std::string frameBuffer__;
  std::vector<FrameContainer> allFrames__;
  GameDialog * dialog__;

  const std::string printGameDialog();

  void readFile();
};

#endif
