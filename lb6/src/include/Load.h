#ifndef __LOAD_H__
#define __LOAD_H__

#include <fstream>
#include <iostream>
#include "board.h"


class Load
{
private:
    std::FILE *file;
    char* prevstate = new char[57 + 1];
    void backup();
public:
    Load() : file(std::fopen("save.txt", "rb"))
    {
        if (!file)  
            throw std::runtime_error("file open failure");
    }
    ~Load() 
    {
        std::fclose(file);
        delete prevstate;
    }

    void PrevState();

    void load();
};

#endif // __LOAD_H__