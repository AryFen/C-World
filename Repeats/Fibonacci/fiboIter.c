# include <stdio.h>

int fiboIter(int n);

int main(void) {
  printf("FiboIter: %d\n", fiboIter(4));
}

int fiboIter(int n) {
  int firstN = 1, secondN = 1;
  for (int i = 2; i < n; i++) {
    int tempN = firstN + secondN;
    firstN = secondN;
    secondN = tempN;
  }
  return secondN;
}