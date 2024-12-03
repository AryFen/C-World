#include <stdio.h>

int factorial(int x);

int main(void) {
  int x;
  printf("Input: ");
  scanf("%d", &x);

  printf("%d\n", factorial(x));

}

int factorial(int x) {
  static int count = 0;
  count++;
  printf("%d\n", count);
  return x * factorial(x-1);
}
