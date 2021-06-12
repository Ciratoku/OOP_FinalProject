#include "include/Load.h"
#include "include/LoadExp.h"

void Load::backup() 
{
    board& Field = board::GetInstance();
    iterator it = Field.begin();
    int i = 0;
    for(iterator it = Field.begin(); it != Field.end(); it++)
    {
        prevstate[i] = '0' + (int)(*it)->getType();
        i++;
    }
    prevstate[49] = Field.getPlayer().getModel();
    prevstate[50] = 'H';
    prevstate[51] = 'P';
    prevstate[52] = '0' + Field.getPlayer().getHP() / 10;
    prevstate[53] = 'X';
    prevstate[54] = 'Y';
    prevstate[55] = '0' + Field.getPlayer().getCoordX();
    prevstate[56] = '0' + Field.getPlayer().getCoordY();
}

void Load::load() 
{
    unsigned long int sof = 0;
	fseek(file, 0, SEEK_END);
	sof = ftell(file);
	rewind(file);
    backup();
    if(sof != 57)
    {
        throw LoadExp("Oversize error\n");
    }
	char* buf = new char[sof];
	fread(buf, sof * sizeof(char), 1, file);
    board& Field = board::GetInstance();
    iterator it = Field.begin();
    int i = 0;
    bool isGunOnField = false;
    while(i < 49)
    {
        if(buf[i] > '7' || buf[i] < '0')
            throw LoadExp("File error (incorrect objects)\n");
        else
        {
            if((buf[i] - '0') == GUN and (*it)->getType() != GUN)
            {
                (*it)->setStrategy(new PickGunStrategy);
                isGunOnField = true;
            }
            if((buf[i] - '0') == MED and (*it)->getType() != MED)
            {
                (*it)->setStrategy(new PickMedStrategy);
            }
            (*it)->setType(CellType(buf[i] - '0')); 
        }
        i++;
        it++;  
    }
    if(buf[49] == 'R')
    {
        if(isGunOnField)
            throw LoadExp("Field is not correct (Gun)\n");
        Field.getPlayer().setModel('R');
        Field.getPlayer().setDMG(30);
    }
    else if(buf[49] == 'P')
    {
        Field.getPlayer().setModel('P');
        Field.getPlayer().setDMG(0);
    }
    else throw LoadExp("File error (Player)\n");
    if(buf[50] != 'H' and buf[51] != 'P')
        return throw LoadExp("File error (HP)\n");
    if(buf[52] < '0' || buf[52] > '9')
        throw LoadExp("HP error\n");
    Field.getPlayer().setHP((buf[52] - '0') * 10);
    if(buf[53] != 'X' and buf[54] != 'Y')
        throw LoadExp("File error (XY)\n");
    if(buf[55] < '0' || buf[55] > '6')
        throw LoadExp("X coord error\n");
     if(buf[56] < '0' || buf[56] > '6')
        throw LoadExp("Y coord error\n");
    Field.getPlayer().setCoord(buf[55] - '0', buf[56] - '0'); 
}

void Load::PrevState() 
{
    board& Field = board::GetInstance();
    iterator it = Field.begin();
    int i = 0;
    while(i < 49)
    {
            std::cout << prevstate[i];
            if((prevstate[i] - '0') == GUN)
            {
                (*it)->setStrategy(new PickGunStrategy);
            }
            if((prevstate[i] - '0') == MED)
            {
                (*it)->setStrategy(new PickMedStrategy);
            }
            (*it)->setType(CellType(prevstate[i] - '0')); 
        i++;
        it++;  
    }
    if(prevstate[49] == 'R')
    {
        Field.getPlayer().setModel('R');
        Field.getPlayer().setDMG(30);
    }
    else
    {
        Field.getPlayer().setModel('P');
        Field.getPlayer().setDMG(0);
    }
    Field.getPlayer().setHP((prevstate[52] - '0') * 10);
    Field.getPlayer().setCoord(prevstate[55] - '0', prevstate[56] - '0');
}


