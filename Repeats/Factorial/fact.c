#include <stdio.h>

int factRec(int n);

int main(void) {
	printf("Factorial: %d\n", factRec(4));
}

int factRec(int n) {
	if (n == 0 || n == 1) {
		return 1;
	} else {
		return n * factRec(n - 1);
	}
}