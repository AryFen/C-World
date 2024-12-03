
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  FILE* file = fopen("arrays.txt", "r");
  char c;

  int min = 100;
  int max = 0;
  int sum = 0;

  while (1) {
    c = fgetc(file);
    if (c == EOF) {
      break;
    }
    if (c == '\n') {
      if (sum % 2 == 1) {
        int avg = sum / 15;
        printf("Sum: %d\n", sum);
        printf("Odd Number Array: Min: %d, Max: %d, Avg: %d\n", min, max, avg);
      }
      else {
        int avg = sum / 10;
        printf("Sum: %d\n", sum);
        printf("Even Number Array: Min: %d, Max: %d, Avg: %d\n", min, max, avg);
      }
      min = 100;
      max = 0;
      sum = 0;
    }
    if ((int) c >= 48 && (int) c <= 57) {
      int n = (int) c - 48;
      printf("n: %d ", n);

      if (n < min) {
        min = n;
      }
      if (n > max) {
        max = n;
      }
      sum += n;
    }
  }
}