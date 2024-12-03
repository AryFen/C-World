#include <stdio.h>

int main(void) 
{

  int arr[] = {2, -2, 4, 5, 1, 0, 4, 5};
  int j;

  for (int i = sizeof(arr)/sizeof(int); i > 0; i--)
  {

    j = 0;

    if (arr[i - 1] < arr[i - 2])
    {
      j = 1;
      break;
    }
  }

  if (j == 0)
  {
    printf("Sorted\n");
  }
  else
  {
    printf("Not Sorted\n");
  }
}
