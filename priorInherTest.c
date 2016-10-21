#include "types.h"
#include "user.h"
#include "stat.h"
#include "fs.h"


int main(int argc, char** argv) {
  int pid = fork();
  if (pid == 0) {
    sleep(1);
    exit(0);
  }
  setPriority(23);
  wait(0);
  exit(0);
}
