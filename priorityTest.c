#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"


int main(int argc, char** argv) {
  int p1;
  int executions = 1000;
  printf(1, "We are about to test priority\n");
  p1 = fork();
  if (p1 == 0) { //child process
    setPriority(2);
    while (executions > 500) {
      printf(1, "Child: %d bottles of beer on the wall\n", executions);
      executions--;

    }
    setPriority(0);
    while (executions > 0) {
      printf(1, "Child: %d bottles of beer on the wall\n", executions);
      executions--;
    }
    exit (0);
  }
  int p2 = fork();
  if (p2 == 0) { //child process
    setPriority(2);
    while (executions > 500) {
      printf(1, "Child: %d bottles of beer on the wall\n", executions);
      executions--;

    }
    setPriority(0);
    while (executions > 0) {
      printf(1, "Child: %d bottles of beer on the wall\n", executions);
      executions--;
    }
    exit (0);
  }
  while (executions > 0) {
    printf(1, "Parent: %d bottles of beer on the wall\n", executions);
    executions--;
  }
  waitpid(p1, 0, 0);
  wait(0);
  exit(0);
}
