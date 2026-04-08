#include <iostream>
#include <list>
#include <map>
using namespace std;

/*
 * Essa implementação de grafo é apenas para estudo
 * a forma mais eficiente é:
 *
 * 1- Substituir map por unordered_map (de rubro negra para hash)
 * 2- Substituir list por vector
 */


class Graph {
    map<int, list<int>> adjList;

public:
    void add_edge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void print()
    {
        cout << "Adjacency list for the Graph: " << endl;
        for (auto i : adjList) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int connectedComponents(Graph &g){
    int counter = 0;
    unordered_set<int> visited;

    for(auto i : ajdList){
        if(visited.count(i.first))
            continue;

        counter++;
        dfs(g, visited, counter, i.first);
    }

    return counter;
}
