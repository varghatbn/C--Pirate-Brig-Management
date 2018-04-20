/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *   File:      CArray.cc
 *   Purpose:   Function implementations for collection class CArray
 *   Author:    Christine Laurendeau
 *   Date:      Jul. 21, 2014
 *   (c) 2014 Christine Laurendeau
 *       ALL RIGHTS RESERVED, DO NOT USE OR RE-POST WITHOUT PERMISSION
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <iostream>
#include <string>
using namespace std;

#include "CArray.h"

CArray::CArray() : size(0)
{ 
  elements = new Cell*[0];
}

//copy constructor
CArray::CArray(const CArray &obj) {
  size = 0;
  for(int i = 0; i<obj.size ; i++){
    add(obj.elements[i]);
  }
}

CArray::~CArray() 
{
  delete [] elements;
}

int CArray::getSize() { return size; }

Cell* CArray::get(int index)
{
  if (index >= 0 && index < size)
    return elements[index];

  return 0;
}
/*takes the cell as a pointer
  adds it to the dynamic cellarray*/
int CArray::add(Cell* cell)
{
  if(size == MAX_CELLS){
    cout<< "sorry, We have reached maximum Capacity" <<endl;
    return C_NOK;
  }
  else{
    if (size == 0) {
      elements = new Cell*[1];
      elements[0] = cell;
    }
    else{
      Cell** tmp  = elements;
      elements = new Cell*[size+1];
      for(int i = 0; i<size ; i++){
        elements[i] = tmp[i];
      }  
      elements[size] = cell;
      delete [] tmp;
    }
    size++;
    return C_OK;
  }
}


void CArray::operator+=(Cell* c){
  add(c);
}

Cell* CArray::operator[](int n){
  return get(n);
}
