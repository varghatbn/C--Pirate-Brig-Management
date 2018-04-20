/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      Storage.cc
 *   Purpose:   Function implementations for collection class Storage
 *   Author:    Vargha Tebyaniyan, Abdulkadir Abdulkadir
 *   Date:      Feb. 20, 2014
 *   
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "Storage.h"
Storage::Storage() {
	cells = new CArray();
}

Storage::~Storage() {
	delete cells;
}

void Storage::retrieve(CArray** cpCells){
  (*cpCells) = new CArray(*cells);
} 

void Storage :: update(UpdateType action , CArray* newCells){
  if(action == add || action == del){
    delete cells;
    cells = newCells;
  }
}
