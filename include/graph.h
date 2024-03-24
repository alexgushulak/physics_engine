#ifndef GRAPH_H
#define GRAPH_H

#define MAXV 10

struct edgenode {
  int y;
  int weight;
  struct edgenode *next;
};

struct graph {
  struct edgenode *edges[MAXV + 1];
  int degree[MAXV + 1];
  int nvertices;
  int nedges;
  int directed;
};

#endif
