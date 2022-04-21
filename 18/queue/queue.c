#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "mylib.h"

struct queue {
  double *items;
  int head;
  int capacity;
  int num_items;
};

queue queue_new() {
  int default_size = 7;
  queue result = emalloc(sizeof *result);
  result->items = emalloc(default_size * sizeof result->items[0]);
  result->capacity = default_size;
  result->head = 0;
  result->num_items = 0;
  return result;
}

void enqueue(queue q, double item) {
  if (q->num_items < q->capacity) {
    q->items[(q->head + q->num_items++) % q->capacity] = item;
  }
}

double dequeue(queue q) {
  if (q->num_items > 0) {
    double result = q->items[q->head];
    if (q->head == q->capacity) {
      q->head = q->head % q->capacity;
    } else {
      q->head++;
    }
    q->num_items--;
    return result;
  }
}

void queue_print(queue q) {
  int x = q->head;
  for(int i=0; i < q->num_items; i++){
    if (x == q->capacity) {
      printf("%.2f\n", q->items[x]);
      x = x % q->capacity;
    } else {
      printf("%.2f\n", q->items[x]);
      x++;
    }
  }
}

void queue_print_info(queue q) {
  int i;
  printf("capacity %d, num_items %d, head %d\n[", q->capacity,
        q->num_items, q->head);
  for (i=0;i<q->capacity;i++) {
    printf("%s%.2f", i==0 ? "" : ", ", q->items[i]);
  }
  printf("]\n");
}

int queue_size(queue q) {
  return q->num_items;
}

queue queue_free(queue q) {
  free(q->items);
  free(q);
  return q;
}
