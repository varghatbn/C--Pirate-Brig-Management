/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Cell.h
 *   Purpose:   Class definition for entity class Cell; manages pirate collection
 *   Author:    Christine Laurendeau, Vargha Tebyaniyan, Abdulkadir Abdulkadir
 *   Date:      Jul. 21, 2014
 *   (c) 2014 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Queue.h"

class Cell 
{
  public:
    Cell(int=MAX_CELL_SPACE);
    bool    fits(Pirate*);
    Queue*  getPirates();
    int     getSpace();
    void    operator+=(int);
    void    operator-=(int);
    void    operator+=(Pirate*);
  private:
    void    reduceSpace(int);
    void    increaseSpace(int);
    static int  nextId;
    int         cellNumber;
    int         spaceRemaining;
    Queue      pirates;
};

#endif

