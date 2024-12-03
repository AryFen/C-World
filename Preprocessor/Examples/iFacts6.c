#include <stdio.h>
 
static inline int square(int x) { return x*x; }

int main(void)
{
  int x = 36/square(6);

  printf("%d\n", x);

  return 0;
}