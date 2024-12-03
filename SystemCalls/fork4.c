#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  if (fork() == 0) {
    for (int i = 0; i <= 100; i += 2) {
      printf("C: %d\n", i);
    }
  }
  else {
    for (int i = 1; i <= 100; i += 2) {
      printf("P: %d\n", i);
    }
  }
}