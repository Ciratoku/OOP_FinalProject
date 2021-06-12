#include "include/LogFile.h"

void LogFile::write(const char *data) 
{
     if (std::fputs(data, file) == EOF)
     {
        throw std::runtime_error("file write failure");
     }
}
