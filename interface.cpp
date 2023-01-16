
#include "interface.h"
#include <QPainter>
#include <QTimer>

const int interface::UPDATERATE = 50; // Auto iterate refresh speed

interface::interface(const Grid &g, QWidget *parent):QWidget(parent)
{
    this->g = g;
    this->autoIterate = false;
    int count = 0;
    this->setWindowTitle("Jeu de la vie - CZARKOWSKI Matthieu");

    QGridLayout *mainLayout = new QGridLayout ;
    mainLayout->setHorizontalSpacing(2);
    mainLayout->setVerticalSpacing(2);

    for (int i = 0; i < this->g.getRowSize(); i++) {
      for (int j = 0; j < this->g.getColumnSize(); j++) {
        if (count <= this->g.getGridSize()) {
          m_button = new QPushButton("");
          m_button->setMinimumSize(10, 10);
          mainLayout->addWidget(m_button,i,j);
          this->buttonArray.push_back(m_button);
          connect(m_button, &QPushButton::clicked, this, [=]{
              if (!this->g.getCell(i,j).isAlive())
              {
                 this->addAliveCell(i, j);
              }
              else
              {
                 this->removeAliveCell(i,j);
              }
          });
          count++;
        }
      }
    }

    next = new QPushButton("iterate");
    mainLayout->addWidget(next,this->g.getRowSize()+1,0,1,0);
    connect(next, &QPushButton::clicked, this, &interface::iterate);

    autoUpdate = new QPushButton("Auto Iterate");
    mainLayout->addWidget(autoUpdate,this->g.getRowSize()+2,0,1,0);
    connect(autoUpdate, &QPushButton::clicked, this, &interface::startAutoIterate);

    stopAutoUpdate = new QPushButton("Stop Auto Iterate");
    mainLayout->addWidget(stopAutoUpdate,this->g.getRowSize()+3,0 ,1,0);
    connect(stopAutoUpdate, &QPushButton::clicked, this, &interface::stopAutoIterate);

    this->updateBoard();
    setLayout(mainLayout);

}

// function that uppdates all the current state of cell in the board
void interface::updateBoard()
{
    for (int i =0;i<this->buttonArray.size();i++)
    {
        if (this->g.getCell(i).isAlive())
        {
            this->buttonArray[i]->setStyleSheet("background-color: black; border:none;");
        }
        else
        {
             this->buttonArray[i]->setStyleSheet("background-color: white; border:none;");
        }
    }
}

// function that make 1 iteration and updates the board
void interface::iterate()
{
    this->g.iteration();
    this->updateBoard();
}

// function adding an alive cell and changing is state on the board
void interface::addAliveCell(int r,int c)
{
    this->g.addCell(r,c);
    this->buttonArray[r*this->g.getColumnSize() + c]->setStyleSheet("background-color: black; border:none;");
}

// function removing an alive cell and changing is state on the board
void interface::removeAliveCell(int r, int c)
{
    this->g.removeCell(r,c);
    this->buttonArray[r*this->g.getColumnSize() + c]->setStyleSheet("background-color: white; border:none;");
}

// function making auto iteration on each chosen updaterate
void interface::autoUpdateBoard(){
    if (this->autoIterate)
    {
        this->iterate();
        QTimer::singleShot(interface::UPDATERATE,this,&interface::autoUpdateBoard);
    }
}

// function that sets if we launch auto update
void interface::startAutoIterate()
{
    this->autoIterate = true;
    this->autoUpdateBoard();
}

// function that sets that we stop auto update
void interface::stopAutoIterate()
{
    this->autoIterate = false;
}

