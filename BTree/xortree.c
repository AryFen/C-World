#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct Node {
  char data;
  struct Node* left;
  struct Node* right;
};

struct Node* XOR (struct Node *a, struct Node *b) {
  return (struct Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

struct Node* Insert(int data, struct Node* parent, int direction);
void L2R(struct Node* node);

void printTree(struct Node *root) {

  if (root == NULL) {
    return;
  }

  printf("Data: %d\n", root->data);
  printTree(root->left);
  printTree(root->right);
}

int main(void) {
  struct Node* root = Insert(1, NULL, 0);
  struct Node* l1 = Insert(2, root, 0);
  struct Node* l2 = Insert(3, l1, 0);
  struct Node* l3 = Insert(4, l2, 0);
  struct Node* r1 = Insert(5, root, 1);
  struct Node* r2 = Insert(6, r1, 1);
  struct Node* r3 = Insert (7, r2, 1);
  L2R(l3);
}

void L2R(struct Node* node) {
  struct Node* child = NULL;
  while (1) {
    struct Node* next = XOR(child, node->left);
    if (next == NULL) {
      break;
    }
    child = node;
    printf("Data: %d\n", node->data);
    node = next;
  }
  struct Node* parent = NULL;
  while (1) {
    struct Node* next = XOR(parent, node->right);
    if (next == NULL) {
      printf("Data: %d\n", node->data);
      break;
    }
    parent = node;
    printf("Data: %d\n", node->data);
    node = next;
  }
}

struct Node* Insert(int data, struct Node* parent, int direction) { 
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->left = XOR(parent, NULL);
  node->right = XOR(parent, NULL);
  if (direction == 0 && parent != NULL) {
    parent->left = XOR(XOR(NULL, parent->left), node);
  }
  if (direction == 1 && parent != NULL) {
    parent->right = XOR(XOR(NULL, parent->right), node);
  }
  return node;
}
