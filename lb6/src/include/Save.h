#ifndef __SAVE_H__
#define __SAVE_H__

#include <fstream>
#include <iostream>
#include "board.h"

class Save
{
private:
    std::FILE *file;
    void write(const char* data);
    char* itoc(int type, char* buffer);
public:
    Save() : file(std::fopen("save.txt", "w"))
    {
        if (!file)  
            throw std::runtime_error("file open failure");
    }
    ~Save() 
    {
        std::fclose(file);
    }   
    void save();
};

#endif // __SAVE_H__