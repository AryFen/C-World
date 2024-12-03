#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
  struct Node* parent;
};

struct Node* NewNode(int data, struct Node* parent) {
  struct Node* curr = malloc(sizeof(struct Node));
  curr->data = data;
  curr->parent = parent;
  curr->left = NULL;
  curr->right = NULL;
  return curr;
}

struct Node* POSuccessor(struct Node* node);

int main(void) {
  struct Node* root = NewNode(1, NULL);
  root->left = NewNode(2, root);
  root->right = NewNode(3, root);
  root->left->left = NewNode(4, root->left);
  root->left->right = NewNode(5, root->left);
  root->right->left = NewNode(6, root->right);
  root->right->right = NewNode(7, root->right);
  
  printf("Data: %d\n", POSuccessor(root->right->right)->data);
}

struct Node* POSuccessor(struct Node* node) {

  if (node->left != NULL) {
    return node->left;
  }
  if (node->right != NULL) {
    return node->right;
  }
  if (node == node->parent->left) {
    struct Node* curr = node->parent;
    while (curr->right == NULL) {
      curr = curr->parent;
    }
    return curr->right;
  }
  else {
    if (node->parent->parent != NULL) {
      struct Node* curr = node->parent->parent;
      while (curr->right == NULL) {
        curr = curr->parent;
      }
      while (curr->right != NULL) {
        curr = curr->right;
      }
      if (curr == node) {
        printf("No preorder successor\n");
      }
      else {
        return curr->right;
      }
    }
    else {
      printf("No preorder successor!\n");
    }
  }
  exit(1);
}