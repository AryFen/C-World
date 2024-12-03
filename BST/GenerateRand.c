#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct Node* newNode(int data);
void Insert(struct Node* root, int data);
void GenerateRandomArray(int arr[]);
void SearchBST(struct Node* root, int data);
void LinearSearchArr(int arr[], int data);

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

int main(void) {

  int arr[10000];

  clock_t startRandArr, endRandArray;
  double timeTakenRandArray;

  startRandArr = clock();
  GenerateRandomArray(arr);
  endRandArray = clock();
  timeTakenRandArray = ((double) endRandArray - startRandArr)/CLOCKS_PER_SEC;
  printf("Array Generation: %f seconds\n", timeTakenRandArray);

  // Setting up BST Clock
  clock_t startBST, endBST;
  double timeTakenBST;

  // Creating BST
  struct Node* root = newNode(arr[0]);
  
  for (int i = 1; i < 10000; i++) {
    Insert(root, arr[i]);
  }

  // Generating number to be searched for
  int randomNumber = rand();
  printf("Number: %d\n", randomNumber);

  // Timing the BST search function
  startBST = clock();
  SearchBST(root, randomNumber);
  endBST = clock();
  timeTakenBST = ((double) endBST - startBST)/CLOCKS_PER_SEC;
  printf("BST: %f seconds\n", timeTakenBST);

  // Setting up Arr Clock
  clock_t startArr, endArr;
  double timeTakenArr;

  // Timing the Arr search function
  startArr = clock();
  LinearSearchArr(arr, randomNumber);
  endArr = clock();
  timeTakenArr = ((double) endArr - startArr)/CLOCKS_PER_SEC;
  printf("Arr: %f seconds\n", timeTakenArr);
}

void GenerateRandomArray(int arr[]) {
  srand(time(0));

  for (int i = 0; i < 10000; i++) {
    arr[i] = rand();
  }
}

void Insert(struct Node* root, int data) {

  struct Node* curr = root;
  while (curr != NULL) {
    if (curr->data == data) {
      printf("Duplicates not allowed!\n");
      return;
    }
    if (data < curr->data) {
      if (curr->left == NULL) {
        break;
      }
      curr = curr->left;
    }
    else {
      if (curr->right == NULL) {
        break;
      }
      curr = curr->right;
    }
  }
  if (data < curr->data) {
    curr->left = newNode(data);
    return;
  }
  curr->right = newNode(data);
  return;
}

struct Node* newNode(int data) {
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void SearchBST(struct Node* root, int data) {

  struct Node* curr = root;

  while (curr != NULL) {
    if (data < curr->data) {
      curr = curr->left;
    }
    else if (data > curr->data) {
      curr = curr->right;
    }
    else {
      printf("BST: Found\n");
      return;
    }
  }
  printf("BST: Not Found\n");
  return;
}

void LinearSearchArr(int arr[], int data) {
  for (int i = 0; i < 10000; i++) {
    if (arr[i] == data) {
      printf("Arr: Found\n");
      return;
    }
  }
}