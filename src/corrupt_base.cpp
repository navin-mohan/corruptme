#include "corrupt_base.h"
#include <fstream>

corruptme::corruptfile::corruptfile(std::fstream f)
{
  file = f;
}
corruptme::corruptfile::corruptfile(std::string filename){
  file = fstream(filename.c_str(),std::ios::in | std::ios::out | std::ios::binary);
}
corruptme::corruptfile::corruptfile(void){}
