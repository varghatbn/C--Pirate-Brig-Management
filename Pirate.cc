/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Pirate.cc
 *   Purpose:   Function implementations for entity class Pirate
 *   Author:    Christine Laurendeau
 *   Date:      Jul. 21, 2014
 *   (c) 2014 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "Pirate.h"

int Pirate::nextId = 1001;

Pirate::Pirate(int s) : space(s) 
{
  id = nextId++;
}


int Pirate::getId()    { return id; }
int Pirate::getSpace() { return space; }



