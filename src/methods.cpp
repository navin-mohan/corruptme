#include <cstring>
#include "methods.h"

corruptme::RandomCharsMethod::RandomCharsMethod(){
  randchars = "#@$#3d"; //just some default chars:
}

bool corruptme::RandomCharsMethod::AddRandomChars(std::string randtxt /*= std::string()*/){
  if(randtxt != std::string())  randchars = randtxt; //by default the random str initialized in ctor is used
  char* buf = new char[randchars.length() + 1];
  std::strcpy(buf,randchars.c_str());
  for(int i=1;i<20;i++){
    file.seekg(i*14);
    file.write(buf,7);
    file.read(buf,7);
  }
  delete[] buf;
  return 1;
}

void corruptme::RandomCharsMethod::setRandChars(std::string r){
  randchars = r;
}
