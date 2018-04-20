/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Cell.cc
 *   Purpose:   Function implementations for entity class Cell
 *   Author:    Christine Laurendeau
 *   Date:      Jul. 21, 2014
 *   (c) 2014 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Cell.h"

int Cell::nextId = 1;

Cell::Cell(int size)
      : spaceRemaining(size)
{
  cellNumber = nextId++;
}

Queue * Cell::getPirates() { return &pirates; }
int     Cell::getSpace()   { return spaceRemaining; }


bool Cell::fits(Pirate* pirate)
{
  if ((spaceRemaining - pirate->getSpace()) < 0)
    return false;

  return true;
}

void Cell::reduceSpace(int pSpace)   { spaceRemaining -= pSpace; }

void Cell::increaseSpace(int pSpace) { spaceRemaining += pSpace; }

void Cell::operator+=(int n){
  increaseSpace(n);
}

void Cell::operator-=(int n){
  reduceSpace(n);
}

void Cell::operator+=(Pirate *p){
  pirates.push(p);
}



