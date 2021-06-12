#ifndef __ITEMOBSERVER_H__
#define __ITEMOBSERVER_H__

#include "Observer.h"

class ItemObserver : public Observer 
{
public:
    void update(const char* new_str) override;
};

#endif // __ITEMOBSERVER_H__