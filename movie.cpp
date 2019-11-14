#include <iostream>
#include <cstring>
#include "media.h"
#include "movie.h"

using namespace std;

Movie::Movie(){ //constructor
}

int Movie::getType(){ //movie type = 0
  return 0;
}

char* Movie::getDirector(){ //returns a pointer to name of director
  return directorName;
}

int* Movie::getRuntime(){ //returns pointer to runtime
  return &runtime;
}

float* Movie::getRating(){ //returns decimal rating
  return &rating;
}
