#include "corrupt_base.h"

#ifndef METHODS_H
#define METHODS_H

namespace corruptme{

  class RandomCharsMethod: public corruptfile //Arjunair's corruption method
  {
    std::string randchars;
  public:
    RandomCharsMethod(std::string filename,bool isBinary=true) : corruptfile(filename,isBinary) {} //using the base ctors
    RandomCharsMethod(FILE *f) : corruptfile(f) {}
    RandomCharsMethod(char* filename) : corruptfile(filename) {}
    RandomCharsMethod();
    void setRandChars(std::string r);
    bool AddRandomChars(std::string randtxt = std::string()); //to do the real corruption: default argument uses the default value from ctor
  };
}

#endif //METHODS_H
