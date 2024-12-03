#include <stdio.h>

#define INCREMENT(x) ++x

int main(void)
{
  char *string = "GeeksQuiz";
  int integer = 10;

  printf("%s  ", INCREMENT(string));
  printf("%d\n", INCREMENT(integer));

  return 0;

  // returns eeksQuiz  11
}