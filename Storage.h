

#ifndef STORAGE_H
#define STORAGE_H
#include <iostream>
using namespace std;
#include "CArray.h"
#include "defs.h"

class Storage {
  public:
    Storage();
   ~Storage();
    void retrieve(CArray**);
    enum UpdateType{add, del};
    void update(UpdateType , CArray* );
    
  private:
    CArray* cells;
};

#endif
