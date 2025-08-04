#include "ASCII_animation.hpp"

FrameContainer::FrameContainer() {}

FrameContainer::~FrameContainer() noexcept {}

void FrameContainer::setFrame( const std::string & collectedFrame )
{
  frame = collectedFrame;
}

Frame::Frame( const std::string & filePath ) : filePath__{ filePath }{}

Frame::~Frame() noexcept {};

std::string Frame::readFile()
{
  // use seekg() to start where the program left off
  std::ifstream frameFile( filePath__, std::ios::in );
  std::stringstream fileStream{};
  std::string fileLine;

  frameFile.exceptions( std::ifstream::failbit | std::ifstream::badbit );
  try
  {
    while( runLoop__ )
    {
      if( !frameFile.is_open() )
      {
        std::cerr << "Failed to open the file" << std::endl;
      }

      frameFile.seekg( framePoint__ );

      if( frameFile.eof() )
      {
        runLoop__ = false;
      }

	    for( int i = 0; i < TEXT_LINES_PLAINS && getline( frameFile, fileLine ); ++i )
	    {
	      fileStream << fileLine << '\n';
	    }

      frameBuffer__ = fileStream.str();

      framePoint__ = frameFile.tellg();

	    frameFile.close();
    }
  }
  catch( std::ifstream::failure error )
  {
	  std::cerr << "Failed to read/write to the file." << '\n' << "Error: " << error.what() << '\n';
  }
  return frameBuffer__;
}

std::ostream & operator<<( std::ostream & stream, Frame & frameBuffer )
{
  frameBuffer.collectFrame();
  int incrementFrame{};
  while( true )
  {
    std::cout << "\x1B[2J\x1B[H";
    stream << frameBuffer.allFrames__.at( incrementFrame ).frame << '\n';
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    ++incrementFrame;
    if( incrementFrame == 3 ) { incrementFrame = 0; }
  }
  return stream;
}

void Frame::collectFrame()
{
  FrameContainer collectFrame;
  for( int i = 0; i < 3; ++i )
  {
    std::string eachFrame = readFile();
    collectFrame.setFrame( eachFrame );
    allFrames__.push_back( collectFrame );
  }
}
