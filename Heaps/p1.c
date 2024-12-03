// Implementing a min heap

#include <stdio.h>
#include <stdlib.h>

struct Heap {
  int* arr;
  int size;
  int capacity;
  int heapType; // 0: min heap, 1: max heap
};

int PopRoot(struct Heap* heap);
void AddSpace(struct Heap* heap);
void PrintHeap(struct Heap* heap);
void Insert(struct Heap* heap, int data);
void PercolateUp(struct Heap* heap, int pos);
void PercolateDown(struct Heap* heap, int pos);
struct Heap* CreateHeap(int capacity, int heapType);

int main(void) {
  int heapType = 0;
  int capacity = 5;
  struct Heap* heap = CreateHeap(capacity, heapType);
  Insert(heap, 10);
  PrintHeap(heap);
  printf("\n");
  Insert(heap, 20);
  PrintHeap(heap);
  printf("\n");
  Insert(heap, 15);
  PrintHeap(heap);
  printf("\n");
  Insert(heap, 5);
  PrintHeap(heap);
  printf("\n");
  printf("Min: %d\n", PopRoot(heap));
  // PrintHeap(heap);
  /*
  printf("\n");
  printf("Min: %d\n", PopRoot(heap));
  PrintHeap(heap);
  printf("\n");
  printf("Min: %d\n", PopRoot(heap));
  PrintHeap(heap);
  printf("\n");
  printf("Min: %d\n", PopRoot(heap));
  PrintHeap(heap);
  printf("\n");
  printf("Min: %d\n", PopRoot(heap));
  PrintHeap(heap);
  */
}

void PrintHeap(struct Heap* heap) {
  for (int i = 0; i < heap->size; i++) {
    printf("Data: %d\n", heap->arr[i]);
  }
}

struct Heap* CreateHeap(int capacity, int heapType) {
  struct Heap* heap = malloc(sizeof(struct Heap));
  heap->arr = malloc(sizeof(int) * capacity);
  heap->size = 0;
  heap->capacity = capacity;
  heap->heapType = heapType;
  return heap;
}

void Insert(struct Heap* heap, int data) {
  if (heap->size == heap->capacity) {
    AddSpace(heap);
  }
  heap->arr[heap->size] = data;
  PercolateUp(heap, heap->size);
  heap->size++;
}

void AddSpace(struct Heap* heap) {
  int* arrPrev = heap->arr;
  heap->arr = malloc(sizeof(int) * heap->capacity * 2);
  for (int i = 0; i < heap->capacity; i++) {
    heap->arr[i] = arrPrev[i];
  }
  heap->capacity *= 2;
}

void PercolateUp(struct Heap* heap, int pos) {
  if (heap->heapType == 0) {
    while (heap->arr[pos] < heap->arr[(pos - 1) / 2] && pos >= 0) {
      int temp = heap->arr[pos];
      heap->arr[pos] = heap->arr[(pos - 1) / 2];
      heap->arr[(pos - 1) / 2] = temp;
      pos = (pos - 1) / 2;
    }
  }
  else {
    while (heap->arr[pos] > heap->arr[(pos - 1) / 2] && pos >= 0) {
      int temp = heap->arr[pos];
      heap->arr[pos] = heap->arr[(pos - 1) / 2];
      heap->arr[(pos - 1) / 2] = temp;
      pos = (pos - 1) / 2;
    }
  }
}

int PopRoot(struct Heap* heap) {
  if (heap->size == 0) {
    return -1;
  }
  int data = heap->arr[0];
  heap->arr[0] = heap->arr[heap->size - 1];
  heap->size--;
  PercolateDown(heap, 0);
  return data;
}

int LeftChildIndex(struct Heap* heap, int pos) {
  int left = pos * 2 + 1;
  if (left >= heap->size) {
    return -1;
  }
  return left;
}

int RightChildIndex(struct Heap* heap, int pos) {
  int right = pos * 2 + 2;
  if (right >= heap->size) {
    return -1;
  }
  return right;
}

void PercolateDown(struct Heap* heap, int pos) {
  if (heap->heapType == 0) {
    while (1) {
      int min;
      int left = LeftChildIndex(heap, pos);
      int right = RightChildIndex(heap, pos);

      if (left == -1 && right == -1) {
        break;
      }
      else if (left != -1 && right == -1) {
        min = left;
        goto skip;
      }
      else if (left == -1 && right != -1) {
        min = right;
        goto skip;
      }

      if (heap->arr[left] < heap->arr[right]) {
        min = left;
      }
      else {
        min = right;
      }

      skip:
      if (heap->arr[pos] < heap->arr[min]) {
        break;
      }
      else {
        int temp = heap->arr[pos];
        heap->arr[pos] = heap->arr[min];
        heap->arr[min] = temp;
        pos = min;
      }
    }
  }
  else {
    while (1) {
      int max;
      int left = LeftChildIndex(heap, pos);
      int right = RightChildIndex(heap, pos);

      if (left == -1 && right == -1) {
        break;
      }
      else if (left != -1 && right == -1) {
        max = left;
        goto skip2;
      }
      else if (left == -1 && right != -1) {
        max = right;
        goto skip2;
      }

      if (heap->arr[left] > heap->arr[right]) {
        max = left;
      }
      else {
        max = right;
      }

      skip2:
      if (heap->arr[pos] > heap->arr[max]) {
        break;
      }
      else {
        int temp = heap->arr[pos];
        heap->arr[pos] = heap->arr[max];
        heap->arr[max] = temp;
        pos = max;
      }
    }
  }
}