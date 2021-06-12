#pragma once


class cell;
class Player;

class Strategy
{
public:
    virtual ~Strategy() {}
    virtual void DoAlgorithm(cell* Cell, Player* player) = 0;
};
