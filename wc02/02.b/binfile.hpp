// 1.c cpplogfile

#ifndef _BINFILE_HPP_
#define _BINFILE_HPP_

#include <stdbool.h>
#include <stdio.h>
#include "file.hpp"
  
class Binfile : public File {
  public:
    //TODO #1: voeg de logfile 'interface' toe
    Binfile();
    ~Binfile();
    bool open(const char* sFilename);
    bool close();
    void write(int nValue);
    void write(char* pBuf);
    void operator>>(char* pBuf);
  private:
    FILE* pFile_;
};

#endif // _LOGFILE_HPP_
