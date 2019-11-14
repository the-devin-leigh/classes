//header guard to make sure is not redefined in other header and class files
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

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

#endif //end of header guard
