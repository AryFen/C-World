// Search Speed Test: BST vs Linear Search Array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
  int data;
  struct Node* left;
  struct Node* right;
};

struct Node* newNode(int data);
void Insert(struct Node* root, int data);
void SearchBST(struct Node* root, int data);
void LinearSearchArr(int arr[], int data);
void generateRandomArray(int arr[]);

int main(void) {

  //Creating Arr
  int arr[10000];

  clock_t startRandArr, endRandArray;
  double timeTakenRandArray;

  startRandArr = clock();
  generateRandomArray(arr);
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

void generateRandomArray(int arr[]) {
  /*
  1. Takes an array as input
  2. Puts values from 0 to array size - 1 in ascending order
  3. Shuffles the values around a lot

  Note: The shuffleCount variable (determines how many shuffles)
  is 50,000 now but the value is arbitrary. 20,000 or 40,000 would
  probably work just fine.

  Note: Shuffling works by taking a random group of contiguous 
  values of some size and swapping it with some other random group of
  contigious values of the same size.
  */

  time_t t;
  srand(time(&t));
  
  for (int i = 0; i < 10000; i++) {
    arr[i] = i;
  }

  int shuffleCount = 20000;
  int count = 0;

  while (count < shuffleCount) {
    int size = 1;
    int startIndex = rand() % 10000;
    if (startIndex + size >= 10000) {
      startIndex -= size;
    }
    int auxArr[size];
    for (int j = 0; j < size; j++) {
      auxArr[j] = arr[startIndex + j];
    }
    int startIndex2 = rand() % 10000;
    if (startIndex2 + size > 10000) {
      startIndex2 -= size;
    }
    int auxArr2[size];
    for (int k = 0; k < size; k++) {
      auxArr2[k] = arr[startIndex2 + k];
    }
    for (int l = 0; l < size; l++) {
      arr[startIndex2 + l] = auxArr[l];
    }
    for (int m = 0; m < size; m++) {
      arr[startIndex + m] = auxArr2[m];
    }
    count++;
  }
}

struct Node* newNode(int data) {
  struct Node * node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
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
      return;
    }
  }
  return;
}

void LinearSearchArr(int arr[], int data) {
  for (int i = 0; i < 10000; i++) {
    if (arr[i] == data) {
      return;
    }
  }
}