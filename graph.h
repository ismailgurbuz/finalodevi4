#ifndef FINALODEVI4_GRAPH_H
#define FINALODEVİ4_GRAPH_H

#define MAX_CITIES 10

typedef struct Edge {
    int target_city_id;
    int distance;
    struct Edge* next;
} Edge;

typedef struct City {
    int city_id;
    char name[50];
    Edge* edges;
} City;

void init_graph(City graph[]);
void add_city(City graph[], int id, const char* name);
void add_edge(City graph[], int from_id, int to_id, int distance);
void DFS(City graph[], int start_city_id, int visited[]);

#endif