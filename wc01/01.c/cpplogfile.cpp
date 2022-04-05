// 1.c cpplogfile
//
// g++ -Wall -o cpplogfile cpplogfile.cpp logfile.cpp
// ./cpplogfile

#include <stdio.h>
#include "logfile.hpp"

int main(int nArgc, char* aArgv[]) {

  //TODO #3: voeg een tweede logbestand toe voor andere gegevens
  Logfile oLog1;
  Logfile oLog2;
  char sBuf[100];
  char sBuf2[100];

  // Initialiseren
  printf("01.c cpplogfile\n\n");
  if (!oLog1.open("log1.txt")) {
    printf("Fout: de logfile 1 kon niet geopend worden!");
    printf("\nAfgebroken :(\n\n");
  };
  if (!oLog2.open("log2.txt")){
    printf("Fout: de logfile 2 kon niet geopend worden!");
    printf("\nAfgebroekn ;(\n\n");
  };



  // Maak 1000 keer
  for (int i = 0; i < 1000; i++) {
    
    sprintf(sBuf, "%d", i*i);
    sprintf(sBuf2, "%d", i*i*i);
    printf("%d | %s | %s", i, sBuf, sBuf2);
    printf("\n");
    oLog1.write(sBuf);
    oLog2.write(sBuf2);
  };

  // Afsluiten
  oLog1.close();
  oLog2.close();
  printf("\nAfgesloten :-)\n\n");
  return 0;
};
