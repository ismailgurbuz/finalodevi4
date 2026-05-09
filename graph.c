#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

void init_graph(City graph[]) {
    for(int i = 0; i < MAX_CITIES; i++) {
        graph[i].city_id = -1; // Boş düğüm
        graph[i].edges = NULL;
    }
}

void add_city(City graph[], int id, const char* name) {
    graph[id].city_id = id;
    strcpy(graph[id].name, name);
    printf("Şehir Eklendi: %s, Bellek Adresi: %p\n", name, (void*)&graph[id]);
}

void add_edge(City graph[], int from_id, int to_id, int distance) {
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->target_city_id = to_id;
    new_edge->distance = distance;
    new_edge->next = graph[from_id].edges;
    graph[from_id].edges = new_edge;
    
    printf("Bağlantı Oluşturuldu: %s -> %s (Adres: %p)\n", graph[from_id].name, graph[to_id].name, (void*)new_edge);
}

// DFS: Derinlemesine Arama
void DFS(City graph[], int current_city_id, int visited[]) {
    visited[current_city_id] = 1;
    printf("Ziyaret Ediliyor (DFS): %s\n", graph[current_city_id].name);

    Edge* temp = graph[current_city_id].edges;
    while (temp != NULL) {
        int next_city = temp->target_city_id;
        if (!visited[next_city]) {
            DFS(graph, next_city, visited);
        }
        temp = temp->next;
    }
}