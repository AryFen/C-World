#include <stdio.h>

#define PLACEHOLDER 0

// Test 1
// #define MULTIPLY(a, b) a*b
// If a=2+3 & b=3+5, the macro is expanded as 2 + 3 * 3 + 5, not 5 * 8; returns 16

// Test 2
// #define MULTIPLY(a, b) (a)*(b)
// Macro expanded as (2 + 3) * (5 + 8); returns 40

int main(void)
{
  printf("%d\n", PLACEHOLDER);
}