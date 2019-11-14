#include <iostream>
#include <string.h>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media(){ //constructor
  /*title = newTitle;
  year = 0;
  type = 0;*/
}

char* Media::getTitle(){ //returns title pointer
  return title;
}

int* Media::getYear(){ //returns year pointer
  return year;
}

int Media::getType(){ //returns type number (0 for movie, etc.)
  return type;
}
