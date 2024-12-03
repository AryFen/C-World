#include <stdio.h>

#define LIMIT(i, count) while (i < count) \
                        { \
                          printf("Geeks "); \
                          i++; \
                        } \

int main(void)
{
  int i = 0;

  LIMIT(i, 3);
  printf("\n");
}