#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <pthread.h>

int main(void) {
  char programName[30];
  FILE* file = fopen("file.txt", "r");
  fgets(programName, 30, file);
  fclose(file);

  int forkReturn = fork();
  if (forkReturn == 0) {
    printf("I am the child.\\n");
    execl("/home/runner/CRepl/SystemCalls/Problems/Problem1/test.out", "/home/runner/CRepl/SystemCalls/Problems/Problem1", NULL);
    perror("In exec(): ");
  }
  else {
    wait(NULL);
    printf("Program execution complete\n");
    exit(0);
  }
}