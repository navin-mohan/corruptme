#include "corrupt_base.h"
#include <fstream>

corruptme::corruptfile::corruptfile(std::string filename,bool isBinary){
  AddFile(filename,isBinary);
}
corruptme::corruptfile::corruptfile(FILE *f){
  AddFile(f);
}
corruptme::corruptfile::corruptfile(const char* filename){
  AddFile(filename);
}
void corruptme::corruptfile::AddFile(std::string filename,bool isBinary){
  if (isBinary)
    file.open(filename.c_str(),std::ios::in | std::ios::out | std::ios::binary);
  else
    file.open(filename.c_str(),std::ios::in | std::ios::out);
  file_open = true;
}
corruptme::corruptfile::corruptfile(void){
  file_open = false;
  c_file_open = false;
}

void corruptme::corruptfile::AddFile(FILE *f){
  file_c = f;
  c_file_open = true;
}

void corruptme::corruptfile::AddFile(const char* filename){
  file_c = fopen(filename,"r+");
  c_file_open = true;
}

corruptme::corruptfile::~corruptfile(){
  if(c_file_open) fclose(file_c);
  if(file_open) file.close();
}
