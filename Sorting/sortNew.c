#include <stdio.h>
#include <stdbool.h>

typedef enum {
  DESC,
  ASC
} SORT;

int main(void) 
{

  SORT sort;
  int preSort;
  int count;
  int arr[100];

  printf("How many numbers would you like to sort?: ");
  scanf("%i", &count);

  printf("In what order (DESC(0)/ASC(1)) would you like to sort? ");
  scanf("%i", &preSort);
  if (preSort != 0 && preSort != 1) {
    printf("Error!");
    return 1;
  }

  sort = preSort;

  for (int i = 0; i < count; i++) {
    printf("Input: ");
    scanf("%i", &arr[i]);
  }

  if (sort == DESC) {

    for (int i = 0; i < count; i++) {
      for (int j = i + 1; j < count; j++) {

        if (arr[i] < arr[j]) {

          int tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
        }
      }
    }
  }
  else {

    for (int i = 0; i < count; i++) {
      for (int j = i + 1; j < count; j++) {

        if (arr[i] > arr[j]) {

          int tmp = arr[i];
          arr[i] = arr[j];
          arr[j] = tmp;
        }
      }
    }
  }
  
  for (int x = 0; x < count; x++) {
    printf("%i ", arr[x]);
  }  

  printf("\n");

}
