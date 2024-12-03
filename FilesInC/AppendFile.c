// Include all required modules

#include <stdio.h>

int main(void) 
{
  // Access file

  FILE *file = fopen("sample.txt", "a");

  // Put line into the end of the file

  fputs("\n", file);
  fputs("We got to the end of the file", file);

  // Close the file

  fclose(file);
}