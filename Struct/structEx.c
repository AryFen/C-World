#include <stdio.h>

int main(void) {
  struct person {
    int age;
    char *name;
  };

  /* typedef struct {
    int age;
    char *name;
  } PERSON; */

  struct person flavio = {37, "Flavio"};

  printf("%s, %d\n", flavio.name, flavio.age);
  flavio.name = "Smith";
  flavio.age = 38;
  printf("%s, %d\n", flavio.name, flavio.age);
}