#include <stdio.h>

void move(int numberOfDiscs, char from, char to, char aux);

int main(void) {
	int n;

	printf("How many disks do you want to move? ");
	scanf("%d", &n);
	move(n, 'A', 'C', 'B');
	printf("\n");
}

void move(int numberOfDiscs, char from, char to, char aux) {
	if (numberOfDiscs == 1) {
		printf("\nMoving Disk 1 from %c to %c", from, to);
	} 
  else {
		move(numberOfDiscs - 1, from, aux, to);
		printf("\nMoving Disk %d from %c to %c", numberOfDiscs, from, to);
		move(numberOfDiscs - 1, aux, to, from);
	}
}