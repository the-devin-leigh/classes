#include <iostream>
#include <cstring>
#include <string.h>

class Media{ //class definition
 public:
  Media();
  char* getTitle();
  int* getYear();
  virtual int getType(); //virtual function returning int representing type of media
 private:
  char title[50]; //stores title
  int year; //stores year
};
  
