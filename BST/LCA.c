#include <stdlib.h>
#include <stdio.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* NewNode(int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct Node* FindLCA(struct Node* root, int n1, int n2);

int main(void) {
  struct Node* root = NewNode(20);
  root->left = NewNode(8);
  root->right = NewNode(22);
  root->left->left = NewNode(4);
  root->left->right = NewNode(12);
  root->left->right->left = NewNode(10);
  root->left->right->right = NewNode(14);

  printf("LCA: %d\n", (FindLCA(root, 4, 14)->data));
}

struct Node* FindLCA(struct Node* root, int n1, int n2) {
  if (root == NULL) {
    return NULL;
  }
  if (root->data > n1 && root->data > n2) {
    return FindLCA(root->left, n1, n2);
  }
  if (root->data < n1 && root->data < n2) {
    return FindLCA(root->right, n1, n2);
  }
  return root;
}