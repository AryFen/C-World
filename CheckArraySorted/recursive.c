#include <stdio.h>

int checkArraySorted(int arr[], int n);

int main(void) 
{

  int arr[] = {7, 6, 5};
  int n = sizeof(arr)/sizeof(int);

  if (checkArraySorted(arr, n) == 0)
  {
    printf("Sorted\n");
  }
  else
  {
    printf("Not Sorted\n");
  } 
}

int checkArraySorted(int arr[], int n)
{
  if (n == 1)
  {
    return 0;
  }
  if (arr[n-1] < arr[n-2])
  {
    return 1;
  }
  checkArraySorted(arr, n - 1);
}