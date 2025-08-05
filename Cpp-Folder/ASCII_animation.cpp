#include "ASCII_animation.hpp"

FrameContainer::FrameContainer() {}

FrameContainer::~FrameContainer() noexcept {}

void FrameContainer::setFrame( const std::string & collectedFrame )
{
  frame = collectedFrame;
}

Frame::Frame( const std::string & filePath ) : filePath__{ filePath }{}

Frame::~Frame() noexcept {};

void Frame::readFile()
{
  std::ifstream frameFile( filePath__, std::ios::in );
  std::stringstream fileStream{};
  std::string fileLine{};
  std::streampos framePoint = 0;

  int linesRead{};
  FrameContainer collectFrame;

  frameFile.exceptions( std::ifstream::failbit | std::ifstream::badbit );
  try
  {
    if( !frameFile.is_open() )
    {
      std::cerr << "Failed to open the file" << std::endl;
    }

    while( getline( frameFile, fileLine ) )
    {
      fileStream << fileLine << '\n';
      ++linesRead;

	    if( linesRead == FRAME_SIZE )
      {
        frameBuffer__ = fileStream.str();
        framePoint = frameFile.tellg();
        collectFrame.setFrame( frameBuffer__ );
        allFrames__.push_back( collectFrame );
        linesRead = 0;
        fileStream.str("");
        fileStream.clear();
      }
    }
    frameFile.close();
  }
  catch( std::ifstream::failure error )
  {
	  std::cerr << "Failed to read/write to the file." << '\n' << "Error: " << error.what() << '\n';
  }
}

std::ostream & operator<<( std::ostream & stream, Frame & frameBuffer )
{
  frameBuffer.readFile();
  int incrementFrame{};
  while( true )
  {
    std::cout << "\x1B[2J\x1B[H";
    stream << frameBuffer.allFrames__.at( incrementFrame ).frame;
    std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
    ++incrementFrame;
    if( incrementFrame == frameBuffer.allFrames__.size() ) { incrementFrame = 0; }
  }
  return stream;
}

void Frame::testFunction()
{
  readFile();
    std::cout << allFrames__.at( 2 ).frame << '\n';
    std::cout << "Current vector size " << allFrames__.size() << '\n';
}
