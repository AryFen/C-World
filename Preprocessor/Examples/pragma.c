#include <stdio.h> 
  
void func1(); 
void func2(); 
  
void __attribute__((constructor)) func1(); 
void __attribute__((destructor)) func2(); 
  
void func1() 
{ 
  printf("Inside func1()\n"); 
} 
  
void func2() 
{ 
  printf("Inside func2()\n"); 
} 
  
int main() 
{ 
  printf("Inside main()\n"); 
  
  return 0; 
} 

// #pragma warn Directive

// #pragma warn -rvl
// This directive hides those warning which are raised when a function which is supposed to return a value does not returns a value.

// # pragma warn -par
// This directive hides those warning which are raised when a function does not uses the parameters passed to it.

// #pragma warn -rch
// This directive hides those warning which are raised when a code is unreachable. For example: any code written after the return statement in a function is unreachable.