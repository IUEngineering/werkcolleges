// 3.c runtime
//
// g++ -Wall -o runtime compiler.cpp parser.cpp runtime.cpp
// ./runtime

#include <stdio.h>
#include <stdlib.h>
#include "parser.hpp"
#include "runtime.hpp"

#define MAX_INVOER 100

int main(int nArgc, char* aArgv[]) {

  Parser oParser;
  Runtime oRuntime;

  char sBuffer[MAX_INVOER + 1];
  uint8_t nCount;

  // Initialiseren
  printf("03.c runtime\n\n");
  
  // Vraag om een regel tekst in sBuffer
  do
  {
    // Lees een regel
    printf("\nCommandoinvoer: ");
    fgets(sBuffer, MAX_INVOER, stdin);
    printf("Gelezen: [%s]\n", sBuffer);

    // Parse de regel in tokens
    nCount = oParser.parse(sBuffer);

    /*// Toon de tokens
    printf("Tokens %d: ", nCount);
    for (uint8_t i = 0; i < nCount; i++) {
      printf("{%s}", oParser.token(i));
    };
    printf("\n");
    */

    // Voer de ingelezen commando's uit
    if (nCount > 0) {
      if (strcmp(oParser.token(0), "knop") == 0) {
        // Goed commando?
        if (nCount == 2) {
          bool bRet = oRuntime.knop(oParser.token(1));
        }
        else {
          printf(" Syntax error! ");
        };
      }
      else
      if (strcmp(oParser.token(0), "led") == 0) {
        // Goed commando?
        if (nCount == 3) {
          oRuntime.led(oParser.token(1), strcmp(oParser.token(2), "on") == 0);
        }
        else {
          printf(" Syntax error! ");
        };
      }
      else
      if (strcmp(oParser.token(0), "label") == 0) {
        // Goed commando?
        if (nCount == 2) {
          oRuntime.label(oParser.token(1));
        }
        else {
          printf(" Syntax error! ");
        };
      }
      else
      if (strcmp(oParser.token(0), "jump") == 0) {
        // Goed commando?
        if (nCount == 2) {
          oRuntime.jump(oParser.token(1));
        }
        else {
          printf(" Syntax error! ");
        };
      }
      //TODO: voeg commando jump toe (hint: dit is bijna het zelfde als commando label)

      else
      if (strcmp(oParser.token(0), "wait") == 0) {
        // Goed commando?
        if (nCount == 2) {
          oRuntime.wait(atoi(oParser.token(1)));
        }
        else {
          printf(" Syntax error! ");
        };
      }
      else {
        printf(" Onbekende invoer! ");
      };
    };

  } while (strcmp(sBuffer, "\n") != 0);

  // Afsluiten
  printf("\nAfgesloten :-)\n\n");
  return 0;
};