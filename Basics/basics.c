/*

Matrix
Binary
Logarithmic
Series

*/

struct Node {
  int data;
};

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int* arr = malloc(sizeof(int) * 5);
  for (int i = 0; i < 5; i++) {
    arr[i] = i + 1;
  }
  for (int i = 0; i < 5; i++) {
    printf("Data: %d\n", arr[i]);
  }
  printf("\n");
  int* arr2 = realloc(arr, sizeof(int) * 6);
  arr2[5] = 6;
  for (int i = 0; i < 6; i++) {
    printf("Data: %d\n", arr2[i]);
  }
  
  struct Node** arr3 = malloc(sizeof(struct Node*) * 3);
  struct Node* node1 = malloc(sizeof(struct Node*));
  node1->data = 10;
  arr3[0] = node1;
  printf("NData: %d", arr3[0]->data);
}