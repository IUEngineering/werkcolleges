// 3.c runtime

/* 
Voorbeeld van de taal:

label x
led rood on
wait 100
led rood off
wait 100
jump x
*/

#ifndef _RUNTIME_HPP_
#define _RUNTIME_HPP_

  #include <stdbool.h>
  #include <stdint.h>
  #include <stdio.h>
  #include <string.h>

  class Runtime {
    public:
      Runtime();
      ~Runtime();
      bool knop(char* sNaam);
      void led(char* sNaam, bool bStatus);
      void label(char* sNaam);
      void jump(char* sNaam);
      void wait(uint16_t nMSec);

    private:
  };

#endif // _RUNTIME_HPP_