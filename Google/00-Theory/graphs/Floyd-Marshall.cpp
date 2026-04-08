//  This algorithm works for both the directed and undirected 
// weighted graphs and can handle graphs with both positive and negative weight edges.
//
//  It does not work for the graphs with negative cycles 
// (where the sum of the edges in a cycle is negative).
//
// Time Complexity  : O(V^3)
// Space Complexity : O(V^2)
//
//  This algorithm finds the cheapest path between all pairs especially 
// good for dense graphs (the cost is based on the number of vertices)
// for sparse graphs we should use Johnson's algorithm.
//

void floydWarshall(vector<vector<int>> &dist) {
    int V = dist.size();
    int INF = 1e8;

    // for each intermediate vertex
    for (int k = 0; k < V; k++) {

        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {

            // Pick all vertices as destination
            // for the above picked source
            for (int j = 0; j < V; j++) {

                // shortest path from i to j 
                if(dist[i][k] != INF && dist[k][j]!= INF )
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
