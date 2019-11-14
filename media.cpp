#include <iostream>
#include <string.h>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media(){
  /*title = newTitle;
  year = 0;
  type = 0;*/
}

char* Media::getTitle(){
  return title;
}

int* Media::getYear(){
  return year;
}

int Media::getType(){
  return type;
}
