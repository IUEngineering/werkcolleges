// 1.b clogfile

#ifndef _LOGFILE_H_
#define _LOGFILE_H_

#include <stdbool.h>
#include <stdio.h>
//TODO #1: voeg de logfile 'interface' toe
FILE* logfile_open(char* sFilename);
bool logfile_close(FILE *pFile);
void logfile_write(FILE *pFile, char* pBuf);

#endif // _LOGFILE_H_

