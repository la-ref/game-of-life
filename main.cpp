#include <iostream>
#include "grid.h"
#include "interface.h"
#include "lifestatistic.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char **argv)
{   
    static const int SIZE_ROW = 20;
    static const int SIZE_COLUMN = 20;
    static const int TORE = false;

    Grid g(SIZE_ROW,SIZE_COLUMN, TORE);
    g.initializeDamier();
    LifeStatistic l(&g);
    // int points[] = {1,2,0,2,6,3,1,5};
    // int size = (sizeof(points)/sizeof(points[0]));
    // g.initializeCaselist(points, size);
    std::cout << l.cellsNumber(true) << " : alive cells" << std::endl;
    std::cout << l.liveCellsPercentage() << "% of alive cells" << std::endl;
    l.cellsNumber(true);
    g.displayBoard();
    g.iterations(0);
    g.displayBoard();
    std::cout << l.cellsNumber(true) << " : alive cells" << std::endl;
    std::cout << l.liveCellsPercentage() << "% of alive cells" << std::endl;

    // Creating the window app
    QApplication app (argc, argv);
    interface window(g);
    window.resize(SIZE_ROW*20,SIZE_COLUMN*20);
    window.show();

    return app.exec();

}
