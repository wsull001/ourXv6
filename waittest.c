#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char** argv) {
  int status;
  int pID;
  pID = fork();
  if(pID != 0) {
    wait(&status);
  }
  else {
    exit(11);
  }
  printf(1, "Child returned: %d\n", status);
  exit(0);
  return 0;
}

