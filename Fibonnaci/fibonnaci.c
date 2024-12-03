// Input: Number Amount
// Inital: 0, n1 = 1
// n2 = n1 + n0
// Continue until for loop ends
// Array to store

#include <stdio.h>

int main(void) {
  
  int stopper;
  int arr[50];

  printf("How many numbers? ");
  scanf("%d", &stopper);

  int nA = 0;
  int nB = 1;
  
  arr[0] = nA;
  arr[1] = nB;

  for (int i = 2; i < stopper; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  for (int n = 0; n < stopper; n++) {
    printf("%d ", arr[n]);
  }
}

