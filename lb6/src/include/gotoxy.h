#ifndef __GOTOXY_H__
#define __GOTOXY_H__

#include <windows.h>

void gotoxy( int column, int line )
{
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
}

#endif // __GOTOXY_H__