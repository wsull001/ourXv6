#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char** argv) {
  int c[4] = {4, 3, 2, 1};
  int d = 7;

  v2p(&c[0], &d);

  printf(1, "%d\n", d);
  v2p(&c[1], &d);
  printf(1, "%d\n", d);
  exit(0);
  return 0;
}
