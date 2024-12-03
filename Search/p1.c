#include <stdio.h>

int main(void) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int x;

  printf("Data: ");
  scanf("%d", &x);

  for (int i = 0; i < 10; i++) {
    if (x == arr[i]) {
      printf("%d is found on index: %d, Found\n", x, i);
      return 0;
    }
  }

  printf("Not found!\n");
  return -1;
}