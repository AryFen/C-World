#include <stdio.h>
#include <stdlib.h>

struct Graph {
  int V;
  int E;
  int** Adj;
};

struct Graph* CreateGraph();

int main(void) {
  struct Graph* graph = CreateGraph();
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      printf("%d ", graph->Adj[i][j]);
    }
    printf("\n");
  }
}

struct Graph* CreateGraph() {
  struct Graph* graph = malloc(sizeof(struct Graph));
  printf("Number of vertices: ");
  scanf("%d", &graph->V);
  graph->Adj = malloc(sizeof(int) * graph->V * graph->V);
  for (int i = 0; i < graph->V; i++) {
    graph->Adj[i] = malloc(sizeof(int) * graph->V);
  }
  printf("Number of edges: ");
  scanf("%d", &graph->E);
  for (int i = 0; i < graph->V; i++) {
    for (int j = 0; j < graph->V; j++) {
      graph->Adj[i][j] = 0;
    }
  }
  for (int i = 0; i < graph->E; i++) {
    int u, v;
    printf("Vertex 1: ");
    scanf("%d", &u);
    printf("Vertex 2: ");
    scanf("%d", &v);
    graph->Adj[u][v] = 1;
    graph->Adj[v][u] = 1;
  }
  return graph;
}