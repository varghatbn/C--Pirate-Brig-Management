/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Brig.h
 *   Purpose:   Class definition for entity class Brig; manages cell collection
 *   Author:    Christine Laurendeau, Vargha Tebyaniyan, Abdulkadir Abdulkadir
 *   Date:      Jul. 21, 2014
 *   (c) 2014 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef BRIG_H
#define BRIG_H

#include <iostream>
#include <string>

using namespace std;

#include "defs.h"
#include "Pirate.h"
#include "CArray.h"
#include "Storage.h"

class Brig 
{
  public:
    Brig();
    void removePirate(int);
    CArray& getCells();
    void operator+=(Pirate* p);
  private:
    int addPirate(Pirate*);
    CArray* cells;
    Storage st;
};

#endif

