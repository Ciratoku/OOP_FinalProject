#include "include/PlayerObserver.h"

void PlayerObserver::update(const char* new_str) 
{
    LogFile logFile;
    logFile.write("Player");
    logFile.write(" ");
    logFile.write(new_str);
    logFile.write("\n");
    std::cout << "Player" << " " << new_str << '\n';
}
