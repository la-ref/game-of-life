#include "grid.h"
// Hope my amazing teacher like english because i like english

// Default constructor creating a 10*10 grid board with cell with no tore
Grid::Grid()
{
    this->row = 10;
    this->column = 10;
    this->board = new Cell[row*column];
    this->tore = false;
}

// Constructor creating a grid  with chosen size creating a board with cell and chosen tore
Grid::Grid(const int row, const int column, const bool tore)
{
    this->row = row;
    this->column = column;
    this->board = new Cell[row*column];
    this->tore = tore;
}

// Copy Constructor
Grid::Grid(const Grid &g)
{
    this->row = g.row;
    this->column = g.column;
    this->tore = g.tore;
    std::copy(g.board, g.board + (g.row*g.column), this->board);
}

// Destructor remove the board
Grid::~Grid()
{

    delete [] this->board;
}
// function returning the row size
int Grid::getRowSize()
{
    return this->row;
}

//  function returning the column size
int Grid::getColumnSize()
{
    return this->column;
}

// function returning the max size of the board
int Grid::getGridSize()
{
    return this->column*this->row;
}

// Giving the cell in a position in the board
Cell Grid::getCell(const int &i) {
   return (this->board[i]);
}

// Giving the cell in a position in the board with coordinate
Cell Grid::getCell(const int &r, const int &c) {
   return (this->board[r*this->column + c]);
}

// add an alive cell at a chosen coordinate
void Grid::addCell(const int &r, const int &c){
    if (this->checkLimits(r, c))
    {   
        this->board[r*this->column + c].setAlive(1);
    }
}

// remove an alive cell at a chosen coordinate
void Grid::removeCell(const int &r, const int &c){
    if (this->checkLimits(r, c))
    {
        this->board[r*this->column + c].setAlive(0);
    }
}

// initialize the grid with of full alive cells
void Grid::initializeFullNotEmpty()
{
    for (int i=0; i< this->row*this->column; i++){
        Cell c(0, 1);
        this->board[i] = c;
    }
}

// initialize the gid with of full not alive cells
void Grid::initializeFullEmpty()
{
    for (int i=0; i< this->row*this->column; i++){
        Cell c;
        this->board[i] = c;
    }
}

// initialize the grid with random alive cells
void Grid::initializeRandom()
{   
    srand( time(NULL) );
    for (int i=0; i< this->row*this->column; i++){
        Cell c(0,rand() % 2);
        this->board[i] = c;
    }
}

// initialize the grid with of alive cells representing a checkerboard
void Grid::initializeDamier()
{
    Cell c;
    for(int i=0; i<this->row; i++)
    {
        for(int k=0; k<this->column; k++)
        {
            c.setAlive((i+k)%2);
            this->board[i*this->column+k] = c;
        }
    }
}

// initialize the grid with of alive cells from a array containing coordinates of where to add a alive cell
void Grid::initializeCaselist(int t[], const int &taille)
{    
    for(int i=1; i<=taille; i++)
    {
        if (i%2 == 0)
        {
            this->addCell(t[i-1],t[i-2]);
        }
    }
}

// function checking if coordinates are inside or board, return true if coordinates are inside, false if they are outside
bool Grid::checkLimits(int r, int c)
{
    return (r < this->row && r >= 0 && c < this->column && c >= 0);
}

// function checking for each cells how many neighbour they have changing their weight
void Grid::checkAround(){
    for(int i=0; i<this->row; i++)
    {
        for(int k=0; k<this->column; k++)
        {
            int counter = 0;
            for (int j=-1; j<2; j++)
            {
                if (!this->tore)
                {
                    if (checkLimits(i+1,k+j))
                    {
                        if (this->board[(((i+1)*column+k)+j) ].isAlive()){
                            counter++;
                        }
                    }
                    if (checkLimits(i-1,k+j)){
                        if (this->board[(((i-1)*column+k)+j) ].isAlive()){
                            counter++;
                        }
                    }
                }
                if (this->tore)
                {
                    int r = (this->row + ((i+1)%this->row))%this->row;
                    int r1 = (this->row + ((i-1)%this->row))%this->row;
                    int c = (this->column + ((k+j)%this->column))%this->column;
                    if (checkLimits(r,c) && this->board[(r*column+c)].isAlive()){ counter++; }
                    if (checkLimits(r1,c) && this->board[(r1*column+c)].isAlive()){ counter++; }
                }
            }
            if (!this->tore)
            {
                if (checkLimits(i,k-1) && this->board[(i*column+(k-1))].isAlive()){ counter++; }
                if (checkLimits(i,k+1) && this->board[(i*column+(k+1))].isAlive()){ counter++; }
            }
            if (this->tore)
            {
                int c = (this->column + ((k-1)%this->column))%this->column;
                int c1 = (this->column+ ((k+1)%this->column))%this->column;
                if (checkLimits(i,c1) && this->board[(i*column+c1)].isAlive()){ counter++; }
                if (checkLimits(i,c) && this->board[(i*column+c)].isAlive()){ counter++; }
            }
            this->board[(i*column+k)].setWeight(counter);
        }
    }
}

// function checking if a cell need to die or be alive depending of their weight and if they are alive or not
void Grid::checkAlive()
{
    for(int i=0; i<this->row; i++)
    {   
        for(int k=0; k<this->column; k++)
        {
            if (this->board[(i*column+k)].getWeight() == 3)
            {
                this->board[(i*column+k)].setAlive(true);
            }
            else if (this->board[(i*column+k)].getWeight() == 2 && this->board[(i*column+k)].isAlive())
            {
                this->board[(i*column+k)].setAlive(true);
            }
            else
            {
                this->board[(i*column+k)].setAlive(false);
            }
        }
    }
}

// function making 1 iteration by checking all the neighbour and checking if they stay alive or not
void Grid::iteration()
{
    this->checkAround();
    this->checkAlive();
}

// function making a number of chosen iterations by checking all the neighbour and checking if they stay alive or not
void Grid::iterations(const int &nb)
{   
    for (int i=0;i<nb; i++)
    {
        this->iteration();
    }
}

// function displaying the board in and if the cells are alive or dead
void Grid::displayBoard()
{
    std::cout << std::endl;
    for(int i=0; i<this->row; i++){
        for(int k=0; k<this->column; k++){
            std::cout << this->board[i*column+k].show();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// function displaying the board in and cells number of neighbour/weight
void Grid::displayWeight()
{
    std::cout << std::endl;
    for(int i=0; i<this->row; i++){
        for(int k=0; k<this->column; k++){
            std::cout << this->board[i*column+k].getWeight();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
