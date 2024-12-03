#include <stdio.h>

#define SIZE 10
int size = 0;
int A[SIZE] = {0};

static int count = 0;

void Binary(int n)
{
  count++;
  if (n < 1)
  {
    for (int i = 0; i < size; i++)
    {
      printf("%d ", A[i]);
    }
    printf("\n");
  }
  else
  {
    A[n-1] = 0;
    Binary(n-1);
    A[n-1] = 1;
    Binary(n-1);
  }
}

int main(void)
{
  int i;

  printf("Input a length of a string: ");
  scanf("%d", &i);

  size = i;

  Binary(i);

  printf("%d\n", count);
}