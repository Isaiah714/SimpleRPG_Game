#include "gamepanel.hpp"

GamePanel::GamePanel()
{
  currentStage__ = "Menu";
  if( currentStage__ == "Menu" )
  {
    std::cout << "\x1B[2J\x1B[H";
    animation("../ASCII-Frames/Menu/Title.txt");
    char input{};
    std::cout << "\n\t\t    Start Game?\n";
    std::cin >> input;
    if( input != ' ' ) { currentStage__ = "Items"; }
  }
  if( currentStage__ == "Items" )
  {
    std::cout << "\x1B[2J\x1B[H";
    givePlayerSetOfItems();
    char input{};
    std::cout << "Enter any character to continue...";
    std::cin >> input;
    if( input != ' ' ) { currentStage__ = "Stage 1"; }
  }
  if( currentStage__ == "Stage 1" )
  {
    animation("../ASCII-Frames/Plains/Slime_Encounter.txt");
    spawnEnemy<Plains>( currentStage__ );
  }
}

void GamePanel::animation( const std::string & filepath )
{
  Frame animateScreen{ filepath };
  std::cout << animateScreen;
}

void GamePanel::givePlayerSetOfItems() 
{
  WeaponItem wep;
  wep.getWeaponItem();
  weapon__ = std::make_pair( wep.getWeaponName(), wep.getWeaponDamage() );

  PotionItem pot;
  pot.getPotionItem();
  potion__ = std::make_pair( pot.getPotionName(), pot.getPotionStat() );

  ArmorItem arm;
  arm.getArmorItem();
  armor__ = std::make_pair( arm.getArmorName(), arm.getArmorDefense() );

  ShieldItem shi;
  shi.getShieldItem();
  shield__ = std::make_pair( shi.getShieldName(), shi.getShieldNegation() );

  std::cout << "You got a "
            << weapon__.first << "\nIt does "
            << weapon__.second << " damage.\n\n"
            << "You got a "
            << potion__.first << "\nThe stat is "
            << potion__.second << "\n\n"
            << "You got "
            << armor__.first << "\nIts defense stat is "
            << armor__.second << "\n\n"
            << "You got a "
            << shield__.first << "\nIt negates "
            << shield__.second << " damage\n\n";  
}

template<typename T>
void GamePanel::spawnEnemy( const std::string & stage )
{
  getEnemy<T>( stage );

  std::cout << "#################################################\n\n";

  std::cout << "You have encountered a " << getName()
            << "\n\nIt has " << getHealth() << " health points"
            << "\n\nIts attack deals " << getAttack() << " damage"
            << "\n\nIts critical attack deals " << getCriticalAttack()
            << " damage"
            << "\n\nIts special attack is " << getSpecialAttack()
            << " points\n";
}

void GamePanel::playercombat()
{
  
}

FrameContainer::FrameContainer() {}

void FrameContainer::setFrame( const std::string & collectedFrame )
{
  frame = collectedFrame;
}

Frame::Frame( const std::string & filePath ) : filePath__{ filePath } {}

void Frame::readFile()
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

const std::string Frame::printGameDialog() const
{
  std::string dialog = "You have encountered a ";
  return dialog;
}

std::ostream & operator<<( std::ostream & stream, Frame & frameBuffer )
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
      std::cout << "\x1B[2J\x1B[H";
      stream << "\n\n\n\n\n\n\n\n" << frameBuffer.printGameDialog() << '\n'
             << frameBuffer.allFrames__.at( incrementFrame ).frame;
      std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
      ++incrementFrame;
      if( incrementFrame == frameBuffer.allFrames__.size() ) { incrementFrame = 0; }
    }
  }
  return stream;
}

void Frame::testFunction()
{
  readFile();
    std::cout << allFrames__.at( 2 ).frame << '\n';
    std::cout << "Current vector size " << allFrames__.size() << '\n';
}
