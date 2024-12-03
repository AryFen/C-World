#include <stdio.h>

int factorial(int x);

int main(void) {
  int x;
  printf("Input: ");
  scanf("%d", &x);

  printf("%d\n", factorial(x));

}

int factorial(int x) {
  if (x > 1) {
    return x * factorial(x-1);
  }
  else {
    return 1;
  }
}