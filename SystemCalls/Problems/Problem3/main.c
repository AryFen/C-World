#include <stdio.h>

int main(void) {
  while (1) {
    int choice;

    printf("1. Create\n");
    printf("2. Read\n");
    printf("3. Write\n");
    printf("4. Delete\n");
    printf("5. Exit\n");
    printf("What would you like to do? ");
    scanf("%d", &choice);

    if (choice == 1) {
      char filename[10];
      printf("Filename: ");
      scanf("%s", filename);
      FILE* file = fopen(filename, "w");
      fclose(file);
    }
    else if (choice == 2) {
      char filename[10];
      printf("Filename: ");
      scanf("%s", filename);
      FILE* file = fopen(filename, "r");

      char text[100];
      fgets(text, 100, file);
      printf("%s\n", text);
      fclose(file);
    }
    else if (choice == 3) {
      char filename[10];
      char toWrite[10];
      printf("Filename: ");
      scanf("%s", filename);
      printf("Write: ");
      scanf("%s", toWrite);
      FILE* file = fopen(filename, "w");
      fprintf(file, "%s", toWrite);
      fclose(file);
    }
    else if (choice == 4) {
      char filename[10];
      printf("Filename: ");
      scanf("%s", filename);
      remove(filename);
    }
    else {
      return 1;
    }
  }
}