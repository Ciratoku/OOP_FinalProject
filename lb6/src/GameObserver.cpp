#include "include/GameObserver.h"

void GameObserver::update(const char* new_str) 
{
    LogFile logFile;
    logFile.write("Game");
    logFile.write(" ");
    logFile.write(new_str);
    logFile.write("\n");
    std::cout << "Game" << " " << new_str << '\n';
}
