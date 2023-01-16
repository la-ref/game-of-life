TEMPLATE = app
TARGET = jeudelavie

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES +=  main.cpp cell.cpp grid.cpp lifestatistic.cpp interface.cpp
HEADERS += cell.h grid.h lifestatistic.h interface.h
