#include "include/ItemObserver.h"

void ItemObserver::update(const char* new_str) 
{
    LogFile logFile;
    logFile.write(new_str);
    logFile.write(" ");
    logFile.write("was picked up by the player");
    logFile.write("\n");
    std::cout << new_str << " " << "was picked up by the player" << '\n';
}