#ifndef GRILLE_HPP
#define GRILLE_HPP
#include "cell.h"
#include <iostream>
#include <time.h>

class Grid
{
    
    private:
        int row,column;
        Cell *board;
        bool tore;
        bool checkLimits(int r, int c);
    public:
        Grid();
        Grid(const int, const int, const bool);
        Grid(const Grid &g);
        ~Grid();
        void initializeFullNotEmpty();
        void initializeFullEmpty();
        void initializeDamier();
        void initializeRandom();
        void initializeCaselist(int t[], const int &taille);
        int getGridSize();
        int getColumnSize();
        int getRowSize();
        Cell getCell(const int &i);
        Cell getCell(const int &r, const int &c);
        void getElement(const int &r, const int &c);
        void addCell(const int &r, const int &c);
        void removeCell(const int &r, const int &c);
        void checkAround();
        void checkAlive();
        void iteration();
        void iterations(const int &nb);
        void displayBoard();
        void displayWeight();
        //friend ostream& operator<<(ostream & sortie, Grid & c);


};

#endif // GRILLE_HPP
