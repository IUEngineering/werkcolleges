// 1.b clogfile
//
// gcc -Wall -o clogfile clogfile.c logfile.c
// ./clogfile

#include <stdio.h>
#include "logfile.h"

int main(int nArgc, char* aArgv[]) {

  FILE *pFile;
  char sBuf[100];

  // Initialiseren
  printf("01.b logfile\n\n");
  pFile = logfile_open("log1.txt");
  if (pFile == NULL) {
    printf("Fout: de logfile kon niet geopend worden!");
    printf("\nAfgebroken :(\n\n");
  };

  // Maak 1000 keer
  for (int i = 0; i < 1000; i++) {
    //TODO #2: wijzig de tekst i kwadraad te tonen
    sprintf(sBuf, "%d ", i*i);

    printf(sBuf);
    logfile_write(pFile, sBuf);
  };

  // Afsluiten
  logfile_close(pFile);
  printf("\nAfgesloten :D\n\n");
  return 0;
};
