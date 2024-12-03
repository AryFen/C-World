// C program to demonstrate stack overflow 
// by creating a non-terminating recursive 
// function. 
#include<stdio.h> 

void fun(int x) 
{ 
  static int count = 0;
	if (x == 1) 
	return; 
  count++;
  printf("%d\n", count);
	x = 6; 
	fun(x); 
} 

int main() 
{ 
  int x = 5; 
  fun(x); 
} 
