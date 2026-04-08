// usually O(E * log(V))
// only non-negative edge weights!

#include <limits.h>
#include <stdio.h>

int V = 10;

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; ++i)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++){
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }
}

// Versão mais moderna:

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> iPair;

void dijkstra(vector<vector<iPair>>& grafo, int origem, int V) { 
    vector<int> dist(V, INT_MAX);
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq; // min-heap

    // na min-heap temos {dist, vertice}
    pq.push({0, origem});
    dist[origem] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;      // O vértice
        int dist_u = pq.top().first;  // A distância até ele
        pq.pop();                     // Remove da fila

        if (dist_u > dist[u]) continue;

        for (auto vizinho : grafo[u]) {
            int v = vizinho.first;
            int peso = vizinho.second;

            if (dist[v] > dist[u] + peso) {
                dist[v] = dist[u] + peso;
                pq.push({dist[v], v});
            }
        }
    }
}
