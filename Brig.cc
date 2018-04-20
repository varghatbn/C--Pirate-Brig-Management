/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Brig.cc
 *   Purpose:   Function implementations for entity class Brig
 *   Author:    Christine Laurendeau
 *   Date:      Jul. 21, 2014
 *   (c) 2014 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Brig.h"

Brig::Brig() {}

int Brig::addPirate(Pirate* pirate)
{
  Cell* newCell;
  int index = -1;
  int rc;

  //retrieve the CArray from Storage
  st.retrieve(&cells);

  for (int i=0; i<cells->getSize(); ++i)
    if ((*(*cells)[i]).fits(pirate))
      index = i;

  if (index >= 0) {
    (*(*cells)[index])+=pirate;
    (*(*cells)[index])-=pirate->getSpace();
  }
  else {
    newCell = new Cell;
    (*cells)+=newCell;
    (*newCell)+=pirate;
    (*newCell)-=pirate->getSpace();
  }
  //update the CArray in Storage
  st.update(st.add , cells);
  return C_OK;
}

void Brig::removePirate(int pID){
  st.retrieve(&cells);
  for (int i = 0; i < cells->getSize(); i++)
    {
      Pirate* pirate = (*(*(*cells)[i]).getPirates())[pID];
      if (pirate == 0) 
        continue;
      (*(*cells)[i])+=pirate->getSpace();
      (*(*(*cells)[i]).getPirates())-=pirate;
      break;
    }
  st.update(st.del, cells);
}

CArray& Brig::getCells() {
  st.retrieve(&cells);
  return *cells;
}

void Brig::operator+=(Pirate* p){
  addPirate(p);
}
