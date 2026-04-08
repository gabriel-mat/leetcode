#include <iostream>
#include <vector>
#include <stack>
#include <queue>

class Graph {
private:
    int V;

public:
    std::vector<std::vector<int>> edges;

    Graph(int numV) : V(numV) {
        edges.resize(V);
    }

    bool areAdjacent(int u, int v){
        for(auto n : edges[u])
            if(n == v)
                return true;

        return false;
    }

    void addEdge(int u, int v){
        edges[u].push_back(v);
    }

    void printGraph() {
        for (int i = 0; i < V; ++i) {
            std::cout << "V" << i << " :";

            for (auto adj : edges[i])
                std::cout << " -> " << adj;

            std::cout << std::endl;
        }
    }

    void process(int node){
        std::cout << node << ' ';
    }

    int graphOrder(){
        return V;
    }
};

bool DFShasPath(Graph &g, std::vector<bool> &seen, int src, int dst){
    if(src == dst) return true;

    seen[src] = true;

    for(int neighbor : g.edges[src]){
        if(seen[neighbor])
            continue;

        if(DFShasPath(g, seen, neighbor, dst))
            return true;
    }

    return false;
}

bool BFShasPath(Graph &g, int src, int dst){
    int current;
    std::queue<int> q;
    std::vector<bool> visited(g.graphOrder(), false);

    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        current = q.front();

        if(current == dst)
            return true;

        q.pop();

        for(int neighbor : g.edges[current]){
            if(visited[neighbor])
                continue;

            visited[neighbor] = true;
            q.push(neighbor);
        }
    }

    return false;

}

int main() {
    Graph g(4);
    int source, dest;
    std::vector<bool> seen(g.graphOrder(), false);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Graph G:" << std::endl;
    g.printGraph();

    source = 0, dest = 3;

    std::cout << "\nDFS approach: " << (DFShasPath(g, seen, source, dest) ? "true" : "false") << std::endl;
    std::cout << "\nBFS approach: " << (BFShasPath(g, source, dest) ? "true" : "false") << std::endl;
    

    std::cout << std::endl;
    
    return 0;
}
