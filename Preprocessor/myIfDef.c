#include <stdio.h>

#define VALUE 1

int main(void)
{
  #if 1
  #ifdef VALUE
    printf("Value defined\n");
  #else
    printf("Value not defined\n");
  #endif
  #endif
}