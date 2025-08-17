#ifndef __GAMEPANEL__
#define __GAMEPANEL__

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#include "enemies.hpp"

#define FRAME_SIZE 21

class GamePanel : public Enemy
{
  public:
  GamePanel();

  protected:
  std::pair<std::string, int> weapon__;
  std::pair<std::string, int> potion__;
  std::pair<std::string, int> armor__;
  std::pair<std::string, int> shield__;
  std::string currentStage__;

  void animation( const std::string & filepath );
  void givePlayerSetOfItems();
  void playercombat();

  template<typename T>
  void spawnEnemy( const std::string & stage );
};

class FrameContainer
{
  public:
  FrameContainer();

  void setFrame( const std::string & collectedFrame );

  std::string frame;
};

class Frame : public GamePanel
{
  public:
  Frame();
  Frame( const std::string & filePath );

  friend std::ostream & operator<<( std::ostream & stream, Frame & frameBuffer);

  void testFunction();

  private:
  const std::string filePath__;
  std::string frameBuffer__;
  std::vector<FrameContainer> allFrames__;

  const std::string printGameDialog() const;

  void readFile();
};


#endif