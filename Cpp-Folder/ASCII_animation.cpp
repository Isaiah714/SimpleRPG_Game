#include "ASCII_animation.hpp"

CollectFrames::CollectFrames() {}

CollectFrames::~CollectFrames() noexcept {}

std::string CollectFrames::getCollectFrame()
{
  return collectFrame__;
}

void CollectFrames::setCollectFrame( const std::string & oneFrame )
{
  collectFrame__ = oneFrame;
}

Frame::Frame( const std::string & filePath ) : filePath__{ filePath }{}

Frame::~Frame() noexcept {};

std::string Frame::readFile()
{
  // use seekg() to start where the program left off
  std::ifstream frameFile( filePath__, std::ios::out );
  std::streampos framePoint{};
  std::stringstream fileStream{};
  std::string fileLine;

  frameFile.exceptions( std::ifstream::failbit | std::ifstream::badbit );

  try
  {
    while( true )
    {
      frameFile.seekg( framePoint );

      if( !frameFile.is_open() )
      {
        std::cerr << "Failed to open the file" << std::endl;
      }

      if( frameFile.eof() )
      {
        loopCondition__ = "END";
        break;
      }
  
	    for( int i = 0; i < TEXT_LINES_PLAINS && getline( frameFile, fileLine ); ++i )
	    {
	      fileStream << fileLine << '\n';
	    }

      frameBuffer__ = fileStream.str();

      framePoint = frameFile.tellg();

	    frameFile.close();
    }
    catch( std::ifstream::failure error )
    {
	    std::cerr << "Failed to open/interact with the file." << '\n';
    }
  }
  return frameBuffer__;
}

void Frame::displayFrame()
{
  int i{};
  CollectFrames frame;
  while( loopCondition__ != "END" )
  {
    frame.setCollectFrame( readFile() );
    allFrames__.push_back( frame );
    // ANSI escape code to clear terminal and move cursor on top
    // Basically clears the terminal
    //std::cout << "\x1B[2J\x1B[H";
    std::cout << allFrames__.at( i ).getCollectFrame() << '\n';
    ++i;

    if( i == 3 ) { break; }
    // Adds a delay before the terminal clears 
    //std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }

  return;
}

/*
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib> // For system("cls") or system("clear")

int main() {
    std::string frame1 = "  O\n /|\\\n / \\";
    std::string frame2 = "  o\n -|\\\n / \\"; // Slightly different for animation

    for (int i = 0; i < 10; ++i) { // Animate for 10 cycles
        // Clear screen
        #ifdef _WIN32
            system("cls");
        #else
            std::cout << "\x1B[2J\x1B[H"; // ANSI escape codes: clear screen + move cursor to top
        #endif

        // Print frame
        if (i % 2 == 0) {
            std::cout << frame1 << std::endl;
        } else {
            std::cout << frame2 << std::endl;
        }

        // Delay
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
*/