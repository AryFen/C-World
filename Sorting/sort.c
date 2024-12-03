// Import all required modules
// Set up array. 'amount' shall represent the amount of numbers input
// Add user input to array
// sortedState used to mark when to end the loop
// Iterate through the list
// If current number is smaller than the next, swap them
// Print the now sorted list

// Import all required modules

#include <stdio.h>
#include <stdbool.h>

int main(void)
{

  // Set up array. 'amount' shall represent the amount of numbers input
  
  int num_array[100];
  int amount;

  printf("How many numbers would you like to sort?: ");
  scanf("%i", &amount);

  // Add user input to array

  for (int i = 0; i < amount; i++)
  {
    printf("Enter a number: ");
    scanf("%i", &num_array[i]);
  }

  // sortedState used to mark when to end the loop

  bool sortedState = false;
  int bound = 0;

  while (sortedState == false)
  {
    sortedState = true;

    // Iterate through the list

    for (int x = 0; x < amount - 1 - bound; x++)
    {

      // If current number is smaller than the next, swap them

      if (num_array[x] < num_array[x + 1])
      {
        int temp = num_array[x];
        num_array[x]= num_array[x + 1];
        num_array[x + 1] = temp;

        sortedState = false;
      }
    }
    bound++;
  }

  // Print the now sorted list

  for (int y = 0; y < amount; y++)
  {
    printf("%i ", num_array[y]);
  }

  printf("\n");
}