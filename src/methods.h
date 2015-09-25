#include "corrupt_base.h"

#ifndef METHODS_H
#define METHODS_H

namespace corruptme{

  class RandomCharsMethod: corruptfile
  {
    std::string randchars;
  public:
    RandomCharsMethod(std::string filename,bool isBinary=true;) : corruptfile(filename,isBinary) {} //using the base ctors
    RandomCharsMethod(FILE *f) : corruptfile(f) {}
    RandomCharsMethod(char* filename) : corruptfile(filename) {}
    RandomCharsMethod();

    bool AddRandomChars(std::string randchars = ""); //to do the real corruption: default argument uses the default value from ctor
  };
}

#endif //METHODS_H
