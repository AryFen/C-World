#include <stdio.h>

//div function prototype
float div(float, float);

#define div(x, y) x/y
 
int main()
{
  //use of macro div
  //Note: %0.2f for taking two decimal value after point
  printf("%0.2f",div(10.0,5.0));

  //removing defined macro div
  #undef div

  //function div is called as macro definition is removed
  printf("\n%0.2f",div(10.0,5.0));
  printf("\n");
  return 0;
}
 
//div function definition
float div(float x, float y){
return y/x;
}