#ifndef CELLULE_HPP
#define CELLULE_HPP
#include <iostream>
class Cell
{
    private:
        int weight;
        int alive;
    public:
        Cell();
        Cell(int w, int alive);
        Cell(Cell &c);
        void addWeight(const int nb);
        void removeWeight(const int nb);
        void setWeight(const int nb);
        void setAlive(const int alive);
        int show();
        int getWeight();
        int getAliveValue();
        bool isAlive();

};

#endif // CELLULE_HPP
