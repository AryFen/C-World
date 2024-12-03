#include <stdio.h>

#define get(a) #a

int main()
{
  // GeeksQuiz is changed to "GeeksQuiz"
  printf("%s\n", get(GeeksQuiz));

  return 0;
}