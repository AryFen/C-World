#include <stdio.h>

extern int EXTERN = 10;

void done(void) {
  extern int ex;
}

int main(void) {
  auto int AUTO = 20;
  static int STATIC = 30;
  register int REGISTER = 40;

  ex = 5;

}