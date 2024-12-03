#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node* newNode(char* data);
struct Node* createTree(char* arr[], int size, int index, struct Node* node);
char* strdup(const char* str);
void printTreeAux(struct Node* node, int index, char* arr[]);
void printTree(char* arr[], int size);
void printTreePre(struct Node *root);
void printTreeIn(struct Node *root);
void printTreePost(struct Node *root);

struct Node {
  char* data;
  struct Node* left;
  struct Node* right;
};

int main(void) {
  FILE* file = fopen("nodes.txt", "r");

  int size = 0;
  char* arr[100];

  int lineLength = 255;
  char line[lineLength];

  while (fgets(line, lineLength, file)) {
    arr[size] = strdup(strtok(line, "\n"));
    size++;
  }

  struct Node* root = createTree(arr, size, 0, root);
  char* printArr[size];
  printTreeAux(root, 0, printArr);
  printTree(printArr, size);
  printf("\n");
  printf("Pre:\n");
  printTreePre(root);
  printf("\n");
  printf("In:\n");
  printTreeIn(root);
  printf("\n");
  printf("Post:\n");
  printTreePost(root);
}

struct Node* newNode(char* data) {
  struct Node* node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct Node* createTree(char* arr[], int size, int index, struct Node* node) {
  if (index >= size) {
    return NULL;
  }
  node = newNode(arr[index]);
  node->left = createTree(arr, size, 2 * index + 1,  node->left);
  node->right = createTree(arr, size, 2 * index + 2,  node->right);
}

char *strdup(const char* str) {
  char* newstring = malloc(strlen(str) + 1); 
  if (newstring)
    strcpy(newstring, str);
  return (newstring);
}

void printTreeAux(struct Node* node, int index, char* arr[]) {
  if (node == NULL) {
    return;
  }
  arr[index] = node->data;
  printTreeAux(node->left, 2 * index + 1, arr);
  printTreeAux(node->right, 2 * index + 2, arr);
}

void printTree(char* arr[], int size) {
  for (int i = 0; i < size; i++) {
    printf("Data: %s\n", arr[i]);
  }
}

void printTreePre(struct Node *root) {

  if (root == NULL) {
    return;
  }

  printf("Data: %s\n", root->data);
  printTreePre(root->left);
  printTreePre(root->right);
}

void printTreeIn(struct Node *root) {

  if (root == NULL) {
    return;
  }

  printTreeIn(root->left);
  printf("Data: %s\n", root->data);
  printTreeIn(root->right);
}

void printTreePost(struct Node *root) {

  if (root == NULL) {
    return;
  }

  printTreePost(root->left);
  printTreePost(root->right);
  printf("Data: %s\n", root->data);
}


