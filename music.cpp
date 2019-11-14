#include <iostream>
#include <cstring>
#include "media.h"
#include "music.h"

using namespace std;

Music::Music(){
}

int Music::getType(){ //indicates music type
  return 2;
}

char* Music::getMusician(){
  return musician;
}

int* Music::getLength(){
  return &length;
}

char* Music::getLabel(){
  return label;
}
