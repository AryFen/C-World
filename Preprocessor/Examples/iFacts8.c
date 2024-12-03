#include <stdio.h>

int VERBOSE = 1;

int main(void)
{
  if (VERBOSE == 1)
  {
    printf("One\n");
  }

  #if VERBOSE >= 2
    printf("Trace Message\n");
  #else
    printf("Message Trace\n");
  #endif

  return 0;
}