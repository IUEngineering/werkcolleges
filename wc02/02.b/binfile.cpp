// 1.c cpplogfile

#include "binfile.hpp"

Binfile::Binfile() {

  // Initialiseer de private variabelen
  pFile_ = NULL;
};

Binfile::~Binfile() {

  // Zorg altijd voor goed opruimen/vrijgeven!
  if (pFile_ != NULL) {
    close();
  };
};

bool Binfile::open(const char* sFilename) {

  // Open de logfile om aan toe te voegen.
  pFile_ = fopen(sFilename, "wb");

  return pFile_ != NULL;
};

bool Binfile::close() { 

  int nRet;

  // Sluit het bestand (0 = succes)
  nRet = fclose(pFile_);
  pFile_ = NULL;
  return nRet == 0;
};

void Binfile::write(int nValue) {

  char sNumber[50], *pBuf;

  // Schrijf alle cijfers en een \n.
  sprintf(sNumber, "%d\n", nValue);
  pBuf = sNumber;
  while (*pBuf > 0) {
    fputc(*pBuf, pFile_);
    pBuf++;
  };
};


void Binfile::write(char* pBuf) {

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

void Binfile::operator>>(char* pBuf) {

  write(pBuf);
};