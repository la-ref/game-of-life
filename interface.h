#ifndef INTERFACE_H
#define INTERFACE_H
#include "grid.h"
#include <string>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>

class interface : public QWidget
{
    Q_OBJECT
    public:
    static const int UPDATERATE;
    explicit interface(const Grid &g, QWidget *parent = 0);
    void iterate();
    void updateBoard();
    void addAliveCell(int,int);
    void removeAliveCell(int,int);
    void startAutoIterate();
    void stopAutoIterate();
    void autoUpdateBoard();

    private:
    bool autoIterate;
    std::vector< QPushButton* > buttonArray;
    QPushButton *m_button;
    QPushButton *next;
    QPushButton *autoUpdate;
    QPushButton *stopAutoUpdate;
    QGridLayout * mainLayout;
    Grid g;

};

#endif // INTERFACE_H
