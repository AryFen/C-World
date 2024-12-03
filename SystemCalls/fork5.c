#include <stdio.h>
#include <unistd.h>

void Experiment1();
void Experiment2();

int main(void) {
  // Experiment1();
  // Experiment2();
}

void Experiment1() {

  printf("\nExperiment 1:\n");

  int id = fork();
  if (id == 0) {
    printf("Hello from C First id: %d\n", id);
  }
  else {
    printf("Hello from P First id: %d\n", id);
  }

  int id2 = fork();
  if (id2 == 0) {
    printf("Hello from C Second id: %d\n", id2);
  }
  else {
    printf("Hello from P Second id: %d\n", id2);
  }
}

void Experiment2() {
  printf("\nExperiment 2:\n");
  if (fork() == fork()) {
    printf("\nTrue\n");
    printf("PID %d from PPID %d\n\n", getpid(), getppid());
    for (int i = 0; i < 1000000; i++) {
      int x = 3;
    }
  }
  else {
    printf("\nFalse\n");
    printf("PID %d from PPID %d\n\n", getpid(), getppid());
    for (int i = 0; i < 1000000; i++) {
      int x = 3;
    }
  }

  /*

  So, 15 was probably the main process. 2680 was the child of 15. 
  2681 and 2682 was the child of 2680. 2683 was the child of 2681? 
  Wouldn't it make more sense for it to be the child of 15? Also,
  what happened to the parent processes at the end? Because 2680
  divides into two different processes; it does not persist. And,
  15 does not divide further it looks like. Unless, 15 stands for
  something else because it the number is very distant and PPID 
  changes regularly. 

  Experiment 2:

  False
  PID 2680 from PPID 15

  False
  PID 2681 from PPID 2680

  True
  PID 2683 from PPID 2681

  False
  PID 2682 from PPID 2680

  */
} 