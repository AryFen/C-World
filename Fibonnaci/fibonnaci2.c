#include <stdio.h>

int main(void) {

  int stopper;

  printf("How many numbers? ");
  scanf("%d", &stopper);
  
  int nA = 0;
  int nB = 1;
  
  printf("%d %d ", nA, nB);

  for (int i = 2; i < stopper; i++) {

    int nC = nA + nB;
    printf("%d ", nC);
    nA = nB;
    nB = nC;
  }
}