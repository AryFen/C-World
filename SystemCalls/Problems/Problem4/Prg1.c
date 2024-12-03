#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
  int arrOdd[15];
  int arrEven[10];
  int forkReturn = fork();
  if (forkReturn == 0) {
    int n = 1;
    for (int i = 0; i < 15; i++) {
      arrOdd[i] = n;
      n += 2;
    }
    FILE* file = fopen("arrays.txt", "a");
    for (int j = 0; j < 15; j++) {
      fprintf(file, "%d ", arrOdd[j]);
    }
    fprintf(file, "\n");
  }
  else {
    int n = 0;
    for (int i = 0; i < 10; i++) {
      arrEven[i] = n;
      n += 2;
    }
    FILE* file = fopen("arrays.txt", "a");
    for (int j = 0; j < 10; j++) {
      fprintf(file, "%d ", arrEven[j]);
    }
    fprintf(file, "\n");
  }
}
