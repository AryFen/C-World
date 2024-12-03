#include <stdio.h>
#include <stdlib.h>

struct Queue {
  int capacity;
  int front;
  int rear;
  int *arr;
  int size;
};

struct Queue* createQueue(int capacity) {
  struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->size = 0;
  queue->front = 0;
  queue->rear = 0;
  queue->arr = (int*) malloc(sizeof(queue->capacity * sizeof(int)));
  return queue;
}

int isFull(struct Queue* queue) {
  if (queue->size == queue->capacity) {
    return 1;
  }
  else {
    return 0;
  }
}

int isEmpty(struct Queue* queue) {
  if (queue->size == 0) {
    return 1;
  }
  else {
    return 0;
  }
}

void enQueue(struct Queue* queue, int data) {
  if (isFull(queue) == 1) {
    printf("Queue is Full!\n");
    return;
  }
  queue->arr[queue->rear] = data;
  if (queue->rear == queue->capacity - 1) {
    queue->rear = 0;
  }
  else {
    queue->rear += 1;
  }
  queue->size++;
}

int deQueue(struct Queue* queue) {
  if (isEmpty(queue) == 1){
    printf("Queue is Empty!\n");
    return 101;
  }
  int returnValue = queue->arr[queue->front];
  queue->arr[queue->front] = 0;
  if (queue->front == queue->capacity - 1) {
    queue->front = 0;
  }
  else {
    queue->front += 1;
  }
  queue->size--;
  return returnValue;
}

int main(void) {
  /*
  printf("Front: %d\n", queue->front);
  printf("Rear: %d\n", queue->rear);
  printf("Size: %d\n", queue->size);
  printf("Capacity: %d\n", queue->capacity);
  */

  struct Queue *queue = createQueue(5);
  printf("E: %d\n", isEmpty(queue));
  printf("Capacity: %d\n", queue->capacity);
  printf("F: %d\n", isFull(queue));
  enQueue(queue, 10);
  printf("F: %d\n", isFull(queue));
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear - 1]);
  for (int i = 0; i < queue->capacity; i++) {
    printf("arr[%d]: %d\n", i, queue->arr[i]);
  }
  enQueue(queue, 20);
  printf("F: %d\n", isFull(queue));
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear - 1]);
  for (int i = 0; i < queue->capacity; i++) {
    printf("arr[%d]: %d\n", i, queue->arr[i]);
  }
  enQueue(queue, 30);
  printf("F: %d\n", isFull(queue));
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear - 1]);
  for (int i = 0; i < queue->capacity; i++) {
    printf("arr[%d]: %d\n", i, queue->arr[i]);
  }
  enQueue(queue, 40);
  printf("F: %d\n", isFull(queue));
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear - 1]);
  for (int i = 0; i < queue->capacity; i++) {
    printf("arr[%d]: %d\n", i, queue->arr[i]);
  }
  deQueue(queue);
  printf("F: %d\n", isFull(queue));
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear - 1]);
  for (int i = 0; i < queue->capacity; i++) {
    printf("arr[%d]: %d\n", i, queue->arr[i]);
  }
  deQueue(queue);
  printf("F: %d\n", isFull(queue));
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear - 1]);
  for (int i = 0; i < queue->capacity; i++) {
    printf("arr[%d]: %d\n", i, queue->arr[i]);
  }
  enQueue(queue, 50);
  printf("F: %d\n", isFull(queue));
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear - 1]);
  for (int i = 0; i < queue->capacity; i++) {
    printf("arr[%d]: %d\n", i, queue->arr[i]);
  }
  enQueue(queue, 60);
  printf("F: %d\n", isFull(queue));
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear - 1]);
  for (int i = 0; i < queue->capacity; i++) {
    printf("arr[%d]: %d\n", i, queue->arr[i]);
  }
  enQueue(queue, 70);
  printf("F: %d\n", isFull(queue));
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear - 1]);
  for (int i = 0; i < queue->capacity; i++) {
    printf("arr[%d]: %d\n", i, queue->arr[i]);
  }
  enQueue(queue, 80);
  printf("F: %d\n", isFull(queue));
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear - 1]);
  for (int i = 0; i < queue->capacity; i++) {
    printf("arr[%d]: %d\n", i, queue->arr[i]);
  }
}