#include "gameloop.hpp"

FrameContainer::FrameContainer() {}

void FrameContainer::setFrame( const std::string & collectedFrame )
{
  frame = collectedFrame;
}

GameLoop::GameLoop() {}

GameLoop::GameLoop( const std::string & filePath ) : filePath__{ filePath } {}

void GameLoop::readFile()
{
  std::ifstream frameFile( filePath__, std::ios::in );
  std::stringstream fileStream{};
  std::string fileLine{};
  std::streampos framePoint = 0;

  int linesRead{};
  FrameContainer collectFrame;

  frameFile.exceptions( std::ifstream::badbit );
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

void GameLoop::setDialog( GameDialog & dialog)
{
  dialog__ = &dialog;
}

GameDialog * GameLoop::getDialog() const
{
  return dialog__;
}

/////////////////////////////DISPLAYS GAME DIALOG/////////////////////////////
const std::string GameLoop::printGameDialog() const
{
  GameDialog * dialog = getDialog();
  std::string outputDialog{};

  if ( dialog->isEnemyTurn )
  {
    std::stringstream ss;
    ss << "You have encountered a " << dialog->printEnemy->getName()
       << "\n\nIt has " << dialog->printEnemy->getHealth() << " health points"
       << "\n\nIts attack deals " << dialog->printEnemy->getAttack() << " damage"
       << "\n\nIts critical attack deals " << dialog->printEnemy->getCriticalAttack()
       << " damage"
       << "\n\nIts special attack is " << dialog->printEnemy->getSpecialAttack()
       << " points\n";

       outputDialog = ss.str();
       return outputDialog;
  }
  else if ( dialog->isPlayerTurn )
  {
    std::stringstream ss;
    ss << "placeholder dialog here";
    outputDialog = ss.str();
    return outputDialog;
  }
  return outputDialog;
}
//////////////////////////////////////////////////////////////////////////////

///////////////////////////DISPLAYING THE GAME LOOP///////////////////////////
std::ostream & operator<<( std::ostream & stream, GameLoop & frameBuffer )
{
  frameBuffer.readFile();
  if( frameBuffer.allFrames__.size() == 1 )
  {
    stream << frameBuffer.allFrames__.at( 0 ).frame;
  }
  else if( frameBuffer.allFrames__.size() > 1 )
  {
    int incrementFrame{};
    while( true )
    {
      //std::cout << "\x1B[2J\x1B[H"; - ncurses should take care of this with their refresh function
      stream << "\n\n\n\n\n\n\n\n" << frameBuffer.printGameDialog() << '\n'
             << frameBuffer.allFrames__.at( incrementFrame ).frame;
      std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
      ++incrementFrame;
      if( incrementFrame == frameBuffer.allFrames__.size() ) { incrementFrame = 0; }
    }
  }
  return stream;
}
//////////////////////////////////////////////////////////////////////////////

void GameLoop::displayGameLoop() const
{
  //this->readFile();
  if( this->allFrames__.size() == 1 )
  {
    //stream << this->allFrames__.at( 0 ).frame;
  }
  else if( this->allFrames__.size() > 1 )
  {
    int incrementFrame{};
    while( true )
    {
      //std::cout << "\x1B[2J\x1B[H"; - ncurses should take care of this with their refresh function
      // use printw();
      std::cout << "\n\n\n\n\n\n\n\n" << this->printGameDialog() << '\n'
             << this->allFrames__.at( incrementFrame ).frame;
      std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
      ++incrementFrame;
      if( incrementFrame == this->allFrames__.size() ) { incrementFrame = 0; }
    }
  }
}
