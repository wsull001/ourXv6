#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char** argv) {
  int p1 = fork();
  if(p1 == 0) {
    printf(1, "Process 1 returns: %d\n", 3);
    exit(3);
  }
  int p2 = fork();
  if (p2 == 0) {
    printf(1, "Process 2 returns: %d\n", 4);
    exit(4);
  }
  int p3 = fork();
  if (p3 == 0) {
    printf(1, "Process 3 returns: %d\n", 5);
    exit(5);
  }
  printf(1, "Wait for process three, identified by return of 5:\n");
  int status; //to keep track of each process's return status and print
  waitPID(p3, &status);
  printf(1, "exit status: %d\n", status);
  printf(1, "\nWait for process two, identified by return of 4:\n");
  waitPID(p2, &status);
  printf(1, "exit status: %d\n", status);
  int t = waitPID(p2, &status);
  printf(1, "Should return -1 because p2 has already been collected: %d\n", t);
  printf(1, "\nWait for process one, identified by return of 3:\n");
  waitPID(p1, &status);
  printf(1, "exit status: %d\n", status);
  exit(0);


}
