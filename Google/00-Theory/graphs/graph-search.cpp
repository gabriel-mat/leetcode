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

void dfs(Graph &g, int source){
    int current;
    std::stack<int> stk;
    std::vector<bool> seen(g.graphOrder(), false);

    stk.push(source);
    
    while(!stk.empty()){
        current = stk.top();
        stk.pop();
        
        if(seen[current]) continue;

        seen[current] = true;
        g.process(current);

        for(int neighbor : g.edges[current])
            if(!seen[neighbor])
                stk.push(neighbor);
    }
}

void bfs(Graph &g, int source){
    int current;
    std::queue<int> fifo;
    std::vector<bool> visited(g.graphOrder(), false);

    fifo.push(source);

    while(!fifo.empty()){
        current = fifo.front();
        fifo.pop();

        if(visited[current]) continue;

        g.process(current);
        visited[current] = true;

        for(int neighbor : g.edges[current])
            if(!visited[neighbor])
                fifo.push(neighbor);
    }
}


int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    std::cout << "Graph G:" << std::endl;
    g.printGraph();

    std::cout << "\nDFS:" << std::endl;
    dfs(g, 0);
    std::cout << std::endl;

    std::cout << "\nBFS:" << std::endl;
    bfs(g, 0);
    std::cout << std::endl;
    
    return 0;
}
