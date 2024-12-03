#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[100];
int p = 0;
int q = 1;

void fiborec(int x, int y, int z);

int main(int argc, char *argv[]) {

  int input;
  input = atoi(argv[1]);

  arr[input] = 0;
  arr[input - 1] = 1;

  fiborec(p, q, input - 2);

  for (int i = input; i > 0; i--) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

void fiborec(int x, int y, int z) {
  int sum = x + y;
  if (z == 0) {
    return;
  }
  arr[z] = sum;
  fiborec(y, sum, z - 1);
}

/* Plan

1. Each step decreases z by 1 until maybe z is 0 or 1
2. int x will past last and y will be sum
3. append sum into arr

*/