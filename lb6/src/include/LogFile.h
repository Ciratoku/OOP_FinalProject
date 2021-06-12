#ifndef __LOGFILE_H__
#define __LOGFILE_H__

#include <fstream>
#include <iostream>

class LogFile
{
private:
    std::FILE *file;
public:
    LogFile() : file(std::fopen("logs.txt", "a"))
    {
        if (!file)  
            throw std::runtime_error("file open failure");
    }
    ~LogFile() 
    {
        std::fclose(file);
    }   
    void write(const char *data);
};

#endif // __LOGFILE_H__