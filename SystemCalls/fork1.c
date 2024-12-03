#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  int i = fork();
  if (i == 0) {
    while (1) {
      printf("C ");
    }
  }
  else {
    printf("Good afternoon\n");
    printf("%d\n", i);
    for (int j = 0; j < 500; j++) {
      printf("P ");
    }
  }
}