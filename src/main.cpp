/*#include "gamepanel.hpp"

int main()
{
  gamePanel();
  return 0;
}*/

#include <ncurses.h>

// Testing with ncurses
int main()
{
  //GameDialog def;
  initscr();
  printw("Hello World\n");
  printw("Different position from screen\n");
  //animation("../ASCII_Frames/Menu/Title.txt", def);
  refresh();
  getch();
  endwin();
  return 0;
}
