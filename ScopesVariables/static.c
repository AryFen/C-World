#include <stdio.h>

int incrementAge();
int staticIncrementAge();
int incrementAgeArray();

int main(void) {
  printf("Age: %d\n", incrementAgeArray());
  printf("Age: %d\n", incrementAgeArray());
  printf("Age: %d\n", incrementAgeArray());
}

int incrementAge() {
  int age = 0;
  age++;
  return age;
}

// Static Variable

int staticIncrementAge() {
  static int age = 0;
  age++;
  return age;
}

// Static Array

int incrementAgeArray() {
  static int ages[3];
  ages[0]++;
  return ages[0];
}

 