#include <fstream>

#ifndef CORRUPTBASE_H
#define CORRUPTBASE_H

namespace corruptme
{
  class corruptfile
  {
    std::fstream file;


  public:
    corruptfile(std::fstream f);
    corruptfile(std::string filename);
    corruptfile(void);

  };
}

#endif //CREATEBASE_H
