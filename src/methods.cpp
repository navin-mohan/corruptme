#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "methods.h"

corruptme::RandomCharsMethod::RandomCharsMethod(){
  randchars = "#@$#3d"; //just some default chars:
}

bool corruptme::RandomCharsMethod::AddRandomChars(std::string randtxt /*= std::string()*/){
  if(randtxt != std::string())  randchars = randtxt; //by default the random str initialized in ctor is used
  char* buf = new char[randchars.length() + 1];
  std::strcpy(buf,randchars.c_str());

  srand(time(NULL));
  for(int i=1;i<100;i++){
    int pos = rand() % 100 + 1;
    file.seekg(pos);
    file.write(buf,7);
    file.read(buf,7);
  }
  delete[] buf;
  return 1;
}

void corruptme::RandomCharsMethod::setRandChars(std::string r){
  randchars = r;
}
