#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* parent;
};

struct MajorArr {
  struct Node** setArr;
  int size;
};

struct MajorArr* Union(struct Node* x, struct Node* y, struct MajorArr* temp);
void MakeSet(int x, struct MajorArr* majorArr);
struct Node* Find(struct Node* node);

int main(void) {
  struct MajorArr* majorArr = malloc(sizeof(struct MajorArr));
  majorArr->setArr = malloc(sizeof(struct Node) * 0);
  majorArr->size = 0;

  MakeSet(1, majorArr);
  MakeSet(2, majorArr);
  MakeSet(3, majorArr);
  MakeSet(4, majorArr);
  MakeSet(5, majorArr);
  MakeSet(6, majorArr);

  for (int i = 0; i < majorArr->size; i++) {
    printf("Data: %d\n", majorArr->setArr[i]->data);
  }
  printf("\n");
  majorArr = Union(majorArr->setArr[0], majorArr->setArr[1], majorArr);
  for (int i = 0; i < majorArr->size; i++) {
    printf("Data: %d\n", majorArr->setArr[i]->data);
  }
}

void MakeSet(int x, struct MajorArr* majorArr) {
  majorArr->setArr = realloc(majorArr->setArr, majorArr->size * sizeof(struct Node) + sizeof(struct Node));
  struct Node* set = malloc(sizeof(struct Node));
  set->data = x;
  set->parent = set;
  majorArr->setArr[majorArr->size] = set;
  majorArr->size++;
}

struct Node* Find(struct Node* node) {
  struct Node* temp = node;
  while (temp->parent != temp) {
    temp = temp->parent;
  }
  return temp;
}

struct MajorArr* Union(struct Node* x, struct Node* y, struct MajorArr* temp) {
  struct MajorArr* majorArr = malloc(sizeof(struct MajorArr));
  majorArr->setArr = malloc(temp->size * sizeof(struct Node) - sizeof(struct Node));
  majorArr->size = temp->size - 1;
  int currIndex = 0;
  for (int i = 0; i < temp->size; i++) {
    if (temp->setArr[i] != Find(x) && temp->setArr[i] != Find(y)) {
      majorArr->setArr[currIndex] = temp->setArr[i];
      currIndex++;
    }
  }
  Find(x)->parent = Find(y);
  majorArr->setArr[currIndex] = Find(y);
  return majorArr;
}