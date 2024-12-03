#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* NewNode(int data) {
  struct Node* curr = malloc(sizeof(struct Node));
  curr->data = data;
  curr->left = NULL;
  curr->right = NULL;
  return curr;
}

int tag = 0;

void preorderTraversal(struct Node *root, struct Node* node) {

  if (root == NULL) {
    return;
  }
  if (tag == 1) {
    printf("Data: %d\n", root->data);
    exit(1);
  }
  if (root == node) {
    tag = 1;
  }

  preorderTraversal(root->left, node);
  preorderTraversal(root->right, node);
}

int main(void) {
  struct Node* root = NewNode(1);
  root->left = NewNode(2);
  root->right = NewNode(3);
  root->left->left = NewNode(4);
  root->left->right = NewNode(5);
  root->left->left->left = NewNode(6);
  root->left->left->right = NewNode(7);

  preorderTraversal(root, root->right);

  /*
  
  int choice;
  printf("Preorder Successor of: ");
  scanf("%d", &choice);

  for (int i = 0; i < 7; i++) {
    if (nodeArr[i]->data == choice) {
      if (i < 6) {
      printf("Data: %d\n", nodeArr[i + 1]->data);
      break;
      }
      else {
        printf("No successor\n");
        break;
      }
    }
    if (i == 6) {
      printf("Node does not exit\n");
    }
  }
  */
}