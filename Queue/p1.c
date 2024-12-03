#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue {
  int capacity;
  int front, rear;
  int *arr;
};

struct Queue* createQueue(int capacity) {
  struct Queue* queue = malloc(sizeof(struct Queue));
  if (!queue) {
    return NULL;
  }
  queue->arr = malloc(capacity * sizeof(int));
  if (!queue->arr) {
    return NULL;
  }
  queue->capacity = capacity;
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

int isEmpty(struct Queue *queue) {
  return (queue->front == -1 && queue->rear == -1);
}

int isFull(struct Queue *queue) {
  int diff;
  if (queue->front > queue->rear) {
    int diff = queue->front - queue->rear;
  }
  else if (queue->front == queue->rear) {
    return 0;
  }
  else {
    int diff = queue->rear - queue->front;
    printf("D: %d\n", diff);
  }
  if (diff >= ((queue->capacity) - 1)) {
    return 1;
  }
  else {
    return 0;
  }
}

void enqueue(struct Queue *queue, int data) {
  if (queue->rear == -1) {
    queue->rear++;
    queue->front++;
    queue->arr[queue->rear] = data; 
    return;
  }
  if (isFull(queue) == 1) {
    printf("Queue Overflow\n");
    return;
  }
  else {
    queue->rear++;
    queue->arr[queue->rear] = data;
    return;
  }
}

int dequeue(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue Underflow\n");
  }
  else {
    queue->front++;
    return (queue->arr[queue->front - 1]);
  }
}

int main(void) {
  struct Queue *queue = createQueue(10);
  printf("E: %d\n", isEmpty(queue));
  printf("Capacity: %d\n", queue->capacity);
  printf("F: %d\n", isFull(queue));
  enqueue(queue, 1);
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear]);
  enqueue(queue, 2);
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear]);
  enqueue(queue, 3);
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear]);
  enqueue(queue, 4);
  printf("Front: %d, Rear: %d\n", queue->arr[queue->front], queue->arr[queue->rear]);
  printf("Diff: %d\n", queue->front - queue->rear);
}

