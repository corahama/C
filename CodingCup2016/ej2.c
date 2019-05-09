#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  typedef struct {
    int n1;
    int n2;
    int time;
  } Arista;

  typedef struct {
    Arista step;
  }

  int n = 4;
  int m = 5;
  Arista arista[m] = {{0, 1, 3}, {0, 1, 5}, {1, 2, 2}, {2, 3, 1}, {2, 3, 4}};

  Arista step[n-1];

  for (int i; i < sizeof(arista)/sizeof(Arista); ++i) {
    step[arista[i].n1] =
  }

  return 0;
}
