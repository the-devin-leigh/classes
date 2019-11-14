#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media{ //parent class declaration
  public:
    Movie();
    virtual int getType(); //virtual function from media class
    char* getDirector();
    int* getRuntime();
    float* getRating();
  private:
    char directorName[20];
    int runtime;
    float rating;
};
