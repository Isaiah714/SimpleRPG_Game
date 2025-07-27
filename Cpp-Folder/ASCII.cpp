#include "ASCII_animation.hpp"

Frame::Frame( const std::string & filePath ) : filePath__{filePath}{}

Frame::~Frame() noexcept {};

std::string Frame::getFrame() const
{
  return frameBuffer__;
}

void Frame::readFile()
{
  // use seekg() to start where the program left off
	
  std::ifstream frameFile{};
  std::streampos framePoint{};
  std::stringstream fileStream{};
  std::string fileLine;

  frameFile.exceptions( std::ifstream::failbit | std::ifstream::badbit );

  try
  {
	frameFile.open( filePath__ );

	for( int i = 0; i < FRAME_LINES_PLAINS && getline( frameFile, fileLine ); ++i )
	{
	  fileStream << fileLine << '\n';
	}

	frameBuffer__ = fileStream.str();
    
	// Saves the position of where the program stopped reading the file.
	framePoint = frameFile.tellg();

	frameFile.close();
  }
  catch( std::ifstream::failure error )
  {
	std::cerr << "Failed to open/interact with the file." << '\n';
  }
}

std::string Frame::displayFrame()
{
  readFile();
  return frameBuffer__;
}