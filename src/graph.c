#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

  struct edgenode e; //malloc(sizeof(struct edgenode));
  struct edgenode p; //malloc(sizeof(struct edgenode));
  struct edgenode *a = malloc(sizeof(struct edgenode));
  struct graph g; //malloc(sizeof(struct graph));

  p.y = 10;
  p.weight = 5;
  p.next = NULL;
  e.weight = 5;
  e.y = 100000;
  e.next = &p;
  printf("%d\n", e.y);
  printf("%d\n", e.weight);
  printf("%p\n", e.next);
  // free(e);
  return 0;

  // command to compile and run code
  // gcc -o graph graph.c
}