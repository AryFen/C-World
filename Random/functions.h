#include <stdio.h>

// Math

# define SUM(x,y) (x+y)
# define MULTIPLY(x,y) (x*y)
# define DIVIDE(x,y) (x/y)

void COMPLETESQUARE(int b, int c)
{
  int termTwo = b/2;
  int termThree = (-1 * (termTwo * termTwo)) + c;
  
  if (termTwo > 0)
  {
    if (termThree > 0)
    {
      printf("(x + %d)^2 + %d\n", termTwo, termThree);
    }
    else if (termThree < 0)
    {
      termThree = -1 * termThree;
      printf("(x + %d)^2 - %d\n", termTwo, termThree);
    }
    else
    {
      printf("(x + %d)^2\n", termTwo);
    }
  }
  if (termTwo < 0)
  {
    termTwo = -1 * termTwo;
    if (termThree > 0)
    {
      printf("(x - %d)^2 + %d\n", termTwo, termThree);
    }
    else if (termThree < 0)
    {
      termThree = -1 * termThree;
      printf("(x - %d)^2 - %d\n", termTwo, termThree);
    }
    else
    {
      printf("(x - %d)^2\n", termTwo);
    }
  }
}

