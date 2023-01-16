#include "cell.h"

// Constructor creating a dead cell with 0 neighbour
Cell::Cell()
{
    this->weight = 0;
    this->alive = 0;
}

// Constructor creating a cell that is alive or not with chosen neighbour
Cell::Cell(int w, int alive)
{
    this->weight = w;
    this->alive = alive;
}

// Constructor copying a value of a cell
Cell::Cell(Cell &c)
{
    this->weight = c.weight;
    this->alive = c.alive;
}

// function adding weight/neighbour to the cell
void Cell::addWeight(int nb)
{
    this->weight = this->weight+nb;
}

// function removing weight/neighbour to the cell
void Cell::removeWeight(int nb)
{
    this->weight = this->weight-nb;
}

// function setting weight/neighbour to the cell
void Cell::setWeight(int nb)
{
    this->weight = nb;
}

// function setting if a cell is alive or not
void Cell::setAlive(int alive)
{
    this->alive = alive;
}

// function returning if a cell is alive or not
int Cell::show()
{
    return this->alive;
}

// function giving a cell number of neighboor
int Cell::getWeight()
{
    return this->weight;
}
// function checking if a cell is alive or not
bool Cell::isAlive()
{
    return this->alive == 1;
}

// function returning if the cell is alive or not
int Cell::getAliveValue()
{
    return this->alive;
}
