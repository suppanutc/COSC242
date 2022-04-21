#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main() {
  queue q = queue_new();
  char c;
  double num;

  enqueue(q, 7.56);
  enqueue(q, 5);
  enqueue(q, 9.678);
  enqueue(q, 7);
  queue_print_info(q);
  queue_print(q);
  printf("%d\n", queue_size(q));
  printf("%.2f\n", dequeue(q));
  //printf("%.2f\n", dequeue(q));
  queue_print(q);
  q = queue_free(q);

  return EXIT_SUCCESS;
}
