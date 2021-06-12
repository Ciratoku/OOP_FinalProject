#include "include/EnemyObserver.h"

void EnemyObserver::update(const char* new_str) 
{
    LogFile logFile;
    logFile.write("Enemy");
    logFile.write(" ");
    logFile.write(new_str);
    logFile.write("\n");
    std::cout << "Enemy" << " " << new_str << '\n';
}