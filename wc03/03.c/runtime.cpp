// 3.c runtime

#include "runtime.hpp"

Runtime::Runtime() {

};

Runtime::~Runtime() {

};

bool Runtime::knop(char* sNaam) {

  printf(" KNOP %s=", sNaam);
  return false;
};

void Runtime::led(char* sNaam, bool bStatus) {

  printf(" LED %s %s ", sNaam, (bStatus ? "on" : "off"));
};

void Runtime::label(char* sNaam) {

  printf(" LABEL %s ", sNaam);
};

void Runtime::jump(char* sNaam) {

  printf(" JUMP %s ", sNaam);
};

void Runtime::wait(uint16_t nMSec) {

  printf(" WAIT %d ", nMSec);
};