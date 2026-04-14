//
// Prim-Jarnik
//

int manhattan_distance(vector<int>& p1, vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);
        unordered_map<int, int> heap_dict;

        for(int i = 0; i < n; ++i)
            heap_dict[i] = INT_MAX;

        heap_dict[0] = 0;
        
        auto cmp = [](pair<int, int> left, pair<int, int> right) { return left.first > right.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);

        min_heap.push({0, 0});
        
        int mst_weight = 0;
        
        while (!min_heap.empty()) {
            auto [w, u] = min_heap.top();
            min_heap.pop();
            
            if (visited[u] || heap_dict[u] < w) continue;
            
            visited[u] = true;
            mst_weight += w;
            
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int new_distance = manhattan_distance(points[u], points[v]);

                    if (new_distance < heap_dict[v]) {
                        heap_dict[v] = new_distance;
                        min_heap.push({new_distance, v});
                    }
                }
            }
        }
        
        return mst_weight;
    }
};


// Podemos remover o hashmap de distâncias
// já que a PQ garante a menor aresta sempre

// essa solução pode ser otimizada com uma parada
// quando todos os pontos já foram conectados (usando um counter)
// a solução atual é mais enxuta, mas tem iterações desnecessárias no final
// (queimando o resto das edges da heap)

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n, false);

        auto cmp = [](pair<int, int> left, pair<int, int> right) { return left.first > right.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);

        min_heap.push({0, 0});
        
        int mst_weight = 0;
        
        while (!min_heap.empty()) {
            auto [w, u] = min_heap.top();
            min_heap.pop();
            
            if (visited[u]) continue;
            
            visited[u] = true;
            mst_weight += w;
            
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int new_distance = manhattan_distance(points[u], points[v]);
                    min_heap.push({new_distance, v});
                }
            }
        }
        
        return mst_weight;
    }
};

// == 

int manhattan_distance(vector<int>& p1, vector<int>& p2) {
    return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int v_count = 0;
        vector<bool> visited(n, false);

        auto cmp = [](pair<int, int> left, pair<int, int> right) { return left.first > right.first; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> min_heap(cmp);

        min_heap.push({0, 0});
        
        int mst_weight = 0;
        
        while (!min_heap.empty()) {
            auto [w, u] = min_heap.top();
            min_heap.pop();
            
            if (visited[u]) continue;
            
            visited[u] = true;
            mst_weight += w;
            
            if(++v_count == n) break;

            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int new_distance = manhattan_distance(points[u], points[v]);
                    min_heap.push({new_distance, v});
                }
            }
        }
        
        return mst_weight;
    }
};

