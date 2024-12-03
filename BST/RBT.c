#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
  int colour; // 0 = Black, 1 = Red
};

void Insert(struct Node* root, int data) {
  struct Node* curr = root;
  struct Node* parent = NULL;
  struct Node* grandparent = NULL;
  while (curr != NULL) {
    if (data < curr->data) {
      grandparent = parent;
      parent = curr;
      curr = curr->left;
    }
    else {
      grandparent = parent;
      parent = curr;
      curr = curr->right;
    }
  }
  curr->data = data;
  curr->colour = 1;
  if (curr == root) {
    curr->colour = 0;
    return;
  }
  if (parent->colour != 0) {
    struct Node* uncle = NULL;
    if (grandparent-> left == parent) {
      uncle = grandparent->right;
    }
    else {
      uncle = grandparent->left;
    }
    if (uncle->colour == 1) {
      uncle->colour = 0;
      parent->colour = 0;
      grandparent->colour = 1;
      printf("Step 3.2 is pending...\n");
    }
    if (uncle->colour == 0) {
      
    }
  }
}

int main(void) {

}