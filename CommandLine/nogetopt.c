#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int num = atoi(argv[1]);
  FILE *file = fopen(argv[2], "r");

  char line[128];
  int count = 0;

  if (file == NULL)
  {
    printf("Error: Could not open file");
    return 1;
  }

  while (fgets(line, sizeof(line), file))
  {
    count++;
    if (count == num + 1)
    {
      return 1;
    }
    printf("%d: %s", count, line);
  }
  printf("\n");
}