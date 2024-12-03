#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* XOR (struct Node *a, struct Node *b) {
  return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

struct Node* NewNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct Node* Insert(struct Node* parent, int direction, int data);

int main(void) {
  struct Node* root = NewNode(1);
  root->right = XOR(NULL, NULL);
  root->left = XOR(NULL, NULL);

  struct Node* temp = Insert(root, 0, 2);
  temp = Insert(temp, 0, 3);
  temp = Insert(temp, 0, 4);

  printf("Data: %d\n", XOR(temp->right, NULL)->data);
}

// Direction - 0: Right, 1: Left
struct Node* Insert(struct Node* parent, int direction, int data) {

  struct Node* node = NewNode(data);
  struct Node* grandparent = XOR(parent->right, NULL);

  if (direction == 0) {
    parent->right = XOR(grandparent, node);
  }
  else {
    parent->left = XOR(grandparent, node);
  }
  node->left = XOR(parent, NULL);
  node->right = XOR(parent, NULL);

  return node;
}

/*

Testing:

int main(void) {

  struct Node* root = NewNode(1);
  struct Node* second = NewNode(2);
  struct Node* third = NewNode(3);
  root->npx = XOR(NULL, second);
  second->npx = XOR(root, third);
  third->npx = XOR(second, NULL);

  printf("Data: %d\n", XOR(root, second->npx)->data);
}

It works

*/