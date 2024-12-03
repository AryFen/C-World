#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  int n;
  printf("Number to Search For: ");
  scanf("%d", &n);
  
  int num[6] = {11, 15, -10, 23, 80, 100};
  for (int i = 0; i <= sizeof(num) / sizeof(num[0]); i++) {
    if (num[i] == n) {
      printf("Number Found at Index %d\n", i);
      break;
    }
  }
}