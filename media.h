#include <iostream>
#include <cstring>
#include <string.h>

class Media{
 public:
  Media();
  string* getTitle();
  int getYear();
  virtual int getType();
 private:
  string* title;
  int year;
  int type;
};
  
