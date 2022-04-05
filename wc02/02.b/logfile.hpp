// 1.c cpplogfile

#ifndef _LOGFILE_HPP_
#define _LOGFILE_HPP_

#include <stdbool.h>
#include <stdio.h>

#include "file.hpp"

class Logfile : public File {
public:
    //TODO #1: voeg de logfile 'interface' toe
    Logfile();
    ~Logfile();
    bool open(const char* sFilename);
    bool close();
    void write(int nValue);
    void write(char* pBuf);
    void operator>>(char* pBuf);
private:
    FILE* pFile_;
};

#endif // _LOGFILE_HPP_
