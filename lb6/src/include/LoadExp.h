#ifndef __LOADEXP_H__
#define __LOADEXP_H__

#include <string>

class LoadExp : public std::exception
{
private:
    std::string msg;
    char* prevstate;
    void backup();
public:
    LoadExp(std::string msg)
    {
        this->msg = msg;
    }
    ~LoadExp() 
    {
        msg = '\0';
    }
    
    std::string What() const;
};

#endif // __LOADEXP_H__