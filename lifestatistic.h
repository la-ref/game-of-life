#ifndef LIFE_HPP
#define LIFE_HPP
#include "grid.h"
#include <iostream>
#include <time.h>

class LifeStatistic
{
    
    private:
        Grid g;
    public:
        LifeStatistic(Grid *grid);
        int cellsNumber(const bool &alive);
        float liveCellsPercentage();

};
#endif
