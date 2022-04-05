// 1.c cpplogfile

#include "logfile.hpp"

Logfile::Logfile() {

  // Initialiseer de private variabelen
  pFile_ = NULL;
};

Logfile::~Logfile() {

  // Zorg altijd voor goed opruimen/vrijgeven!
  if (pFile_ != NULL) {
    close();
  };
};

bool Logfile::open(const char* sFilename) {

  // Open de logfile om aan toe te voegen.
  pFile_ = fopen(sFilename, "a");

  return pFile_ != NULL;
};

bool Logfile::close() { 

  int nRet;

  // Sluit het bestand (0 = succes)
  nRet = fclose(pFile_);
  pFile_ = NULL;
  return nRet == 0;
};

void Logfile::write(int nValue) {

  char sNumber[50], *pBuf;

  // Schrijf alle cijfers en een \n.
  sprintf(sNumber, "%d\n", nValue);
  pBuf = sNumber;
  while (*pBuf > 0) {
    fputc(*pBuf, pFile_);
    pBuf++;
  };
};


void Logfile::write(char* pBuf) {

  char sNewline[] = "\n";

  // Schrijf alle letters.
  while (*pBuf > 0) {
    fputc(*pBuf, pFile_);
    pBuf++;
  };

  // Sluit af met \n
  pBuf = sNewline;
  while (*pBuf > 0) {
    fputc(*pBuf, pFile_);
    pBuf++;
  };
};

void Logfile::operator>>(char* pBuf) {

  write(pBuf);
};