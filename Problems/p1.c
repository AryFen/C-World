#include <stdio.h>

int main(void) {
  int size;
  static int l;
  printf("How many elements do you want?: ");
  scanf("%d", &size);

  int arr[size];

  for (int i = 0; i < size; i++) {
    printf("Enter value: ");
    scanf("%d", &arr[i]);
  }

  int k;
  printf("How many parts do you want to split?: ");
  scanf("%d", &k);

  for (int o = 0; o < size; o++) {
    printf("Data: %d\n", arr[o]);
  }

  printf("\n");

  int temp[k];
 
  for (int j = 0; j < k; j++) {
    temp[j] = arr[j];
  }

  for (l = 0; l < size - k; l++) {
    arr[l] = arr[l + k];
  }

  int count = 0;
  for (int m = l; m < size; m++) {
    arr[m] = temp[count];
    count++;
  }

  for (int n = 0; n < size; n++) {
    printf("Data: %d\n", arr[n]);
  }

  return 0;
}