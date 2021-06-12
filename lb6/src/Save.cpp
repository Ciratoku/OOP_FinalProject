#include "include/Save.h"

void Save::save() 
{
    board& Field = board::GetInstance();
    char buffer[2] = {'\0'};
    for(iterator it = Field.begin(); it != Field.end(); it++)
    {
        sprintf(buffer, "%d", (*it)->getType());
        write(buffer);
        //write(itoc((*it)->getType(), buffer));
    }
    buffer[0] = Field.getPlayer().getModel();
    write(buffer);
    write("HP");
    buffer[0] = '0' + Field.getPlayer().getHP() / 10;
    write(buffer);
    write("XY");
    buffer[0] = '0' + Field.getPlayer().getCoordX();
    write(buffer);
    buffer[0] = '0' + Field.getPlayer().getCoordY();
    write(buffer);
}

void Save::write(const char* data) 
{
    if (std::fputs(data, file) == EOF)
    {
        throw std::runtime_error("file write failure");
    }
}

char* Save::itoc(int type, char* buffer) 
{
    int digit = -1;
    int cpy = type;
    while(cpy)
    {
        cpy /= 10;
        digit++;
    }
    while(type)
    {
        buffer[digit] = (type % 10) + '0';
        type /= 10;
        digit--;
    }
    return buffer;
}


