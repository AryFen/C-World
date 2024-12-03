# include <stdio.h>

int fiboRec(int n);

int main(void) {
  printf("Fibo: %d\n", fiboRec(4));
}

int fiboRec(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  else {
    return fiboRec(n - 1) + fiboRec(n - 2);
  }
}