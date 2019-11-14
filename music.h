#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media{
 public:
  Music();
  virtual int getType();
  char* getMusician();
  int* getLength();
  char* getLabel();
 private:
  char musician[20];
  int length;
  char label[20];
};
  
