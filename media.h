#include <iostream>
#include <cstring>
#include <string.h>

class Media{
 public:
  Media();
  char* getTitle();
  int* getYear();
  virtual int getType();
 private:
  char title[50];
  int year;
};
  
