#include <stdio.h>

int main(void) {
  unsigned char a = 0;
  signed char b = 0;

  while (1) {
    printf("a= %d   b= %d\n", a, b);
    a++;
    b++;
  }
}