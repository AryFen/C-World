// Include all required modules

#include <stdio.h>

int main(void) {
  // Access the file

  FILE *file = fopen("sample.txt", "r");
  int c;

  while(1)
  {
    // Move through the file character by character

    c = fgetc(file);

    // If you reach the end of the file, exit the loop

    if (feof(file))
    {
      break;
    }
    // Read character

    printf("%c", c);
  }
  // Add new line

  printf("\n");

  // Close the file

  fclose(file);

  return 0;
}