#include "lifestatistic.h"
#include "grid.h"
#include "cell.h"
#include <iostream>

// Constructor taking a reference of a grid
LifeStatistic::LifeStatistic(Grid *grid)
{
    this->g = *grid;
}

// function returning the number of alive cells or dead cells in the grid depening of the parameter : true = alive, false = dead
int LifeStatistic::cellsNumber(const bool &alive)
{
    int counter = 0;
    for (int i = 0; i < this->g.getGridSize(); i++)
    {   
        if (this->g.getCell(i).isAlive() == alive)
        {
            counter++;
        }
    }
    return counter;
}

// function returning the percentage of alive cells in the grid
float LifeStatistic::liveCellsPercentage()
{
    float alive = this->cellsNumber(true);
    return ((alive/this->g.getGridSize())*100);
}
