#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int opt;
  int num;
  FILE *file;
  int count = 0;
  

  while ((opt = getopt(argc, argv, ":n:f:")) != -1)
  {
    switch(opt)
    {
      case 'n':
        num = atoi(optarg);
      case 'f':
        if ((file = fopen(optarg, "r")))
        {
          char line[128];

          while (fgets(line, sizeof(line), file))
          {
            count++;
            if (count == num + 1)
            {
              exit(1);
            }
            printf("%d: %s", count, line);
          }
        }
    }
    printf("\n");
  }
}