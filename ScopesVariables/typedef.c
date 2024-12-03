#include <stdio.h>

// typedef SALARY

// typedef int SALARY;

// Enumerated Type

typedef enum {
  monday,
  tuesday,
  wednesday,
  thursday,
  friday,
  saturday,
  sunday
} WEEKDAY;

int main(void) {
    WEEKDAY day = monday;

    printf("%d\n", day);
    printf("%d\n", monday);
    printf("%d\n", tuesday);
    printf("%d\n", wednesday);
    printf("%d\n", thursday);
    printf("%d\n", friday);
    printf("%d\n", saturday);
    printf("%d\n", sunday);

    if (day == monday) {
      printf("It's monday.\n");
    }
    else {
      printf("It's not monday!\n");
    }
}