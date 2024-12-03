#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  int rTag;
  int lTag;
  struct Node* left;
  struct Node* right;
};

void printTree(struct Node *root) {
  if (root->lTag == 1) {
    printTree(root->left);
  }
  printf("Data: %d\n", root->data);
  if (root->rTag == 1) {
    printTree(root->right);
  }
}

struct Node* inorderSuccessor(struct Node* P);
void inorderTraverse(struct Node* dummy);

struct Node* NewNode(int data) {
  struct Node* curr = malloc(sizeof(struct Node));
  curr->data = data;
  curr->right = NULL;
  curr->left = NULL;
  curr->rTag = -1;
  curr->lTag = -1;
  return curr;
}

int main(void) {
  struct Node* root = NewNode(1);
  root->lTag = 1;
  root->rTag = 1;

  struct Node* dummy = NewNode(-1);
  dummy->lTag = 1;
  dummy->rTag = 1;
  dummy->left = root;
  dummy->right = dummy;

  root->left = NewNode(5);
  root->left->lTag = 1;
  root->left->rTag = 0;
  root->left->right = root;

  root->left->left = NewNode(2);
  root->left->left->lTag = 0;
  root->left->left->rTag = 0;
  root->left->left->left = dummy;
  root->left->left->right = root->left;

  root->right = NewNode(11);
  root->right->lTag = 1;
  root->right->rTag = 1;

  root->right->left = NewNode(16);
  root->right->left->lTag = 0;
  root->right->left->rTag = 0;
  root->right->left->left = root;
  root->right->left->right = root->right;

  root->right->right = NewNode(31);
  root->right->right->lTag = 0;
  root->right->right->rTag = 0;
  root->right->right->left = root->right;
  root->right->right->right = dummy;

  printTree(root);
}

/*
Data: 2
Data: 5
Data: 1
Data: 16
Data: 11
Data: 31
*/

struct Node* inorderSuccessor(struct Node* P) {
  if (P->rTag == 0) {
    return P->right;
  }
  else {
    struct Node* temp = P->right;
    while (temp->lTag == 1) {
      temp = temp->left;
    }
    return temp;
  }
}

void inorderTraverse(struct Node* dummy) {
  struct Node* curr = inorderSuccessor(dummy);
  while (curr != dummy) {
    printf("Data: %d\n", curr->data);
    curr = inorderSuccessor(curr);
  }
}