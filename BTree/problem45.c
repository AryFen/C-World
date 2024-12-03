#include <stdio.h>
#include <stdlib.h>

#define K 3

struct Node {
  int data;
  struct Node* childArr[K];
};

struct Node* NewNode(int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  return node;
}

void CompleteTree(struct Node* node, int height, int nodeArr[], int index, int length);
void PrintTree(struct Node *root);
int Power(int base, int exp);

int main(void) {

  int nodeArr[] = {1, 2, 5, 6, 7, 3, 8, 9, 10, 4};
  int height = 2;

  struct Node* root = malloc(sizeof(struct Node));
  CompleteTree(root, height, nodeArr, 0, 10);
  PrintTree(root);
}

void PrintTree(struct Node *root) {

  if (root == NULL) {
    return;
  }

  printf("Data: %d\n", root->data);
  PrintTree(root->childArr[0]);
  PrintTree(root->childArr[1]);
  PrintTree(root->childArr[2]);
}

int Power(int base, int exp) {
  int answer = 1;
  for (int i = 0; i < exp; i++) {
    answer *= base;
  }
  return answer;
}

void CompleteTree(struct Node* node, int height, int nodeArr[], int index, int length) {
  if (height == 0 || node->data == nodeArr[length - 1]) {
    return;
  }
  node->data = nodeArr[index];
  int distance = 0.5 * (Power(3, height) - 1);
  for (int i = 0; i < K; i++) {
    node->childArr[i] = NewNode(nodeArr[index + (distance * i + 1)]);
  }
  for (int i = 0; i < K; i++) {
    int newIndex = index + (distance * i + 1);
    CompleteTree(node->childArr[i], height - 1, nodeArr, newIndex, length);
  }
}


