#include <fstream>
#include <cstdio>

#ifndef CORRUPTBASE_H
#define CORRUPTBASE_H

namespace corruptme
{
  class corruptfile
  {

  protected:

    std::fstream file;    //c++ filestream object
    FILE *file_c;         //c style file ptr
    bool c_file_open,file_open;  //keep track of open files

  public:
    corruptfile(std::string filename,bool isBinary = true); //to asscociate the file obj with the file filename
    corruptfile(FILE *f);         //to init the c file ptr with FILE* f
    corruptfile(char* filename);  //to create a FILE ptr to the file filename
    corruptfile(void);            // default ctor
    ~corruptfile();               //dtor : closes all open file streams

  };
}

#endif //CREATEBASE_H
