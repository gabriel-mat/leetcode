class Solution {
public:
    // i, j, w
    // typedef tuple<int, int, int> edge;
    using edge = tuple<int, int, int>;

    int n, m;

    int minimumObstacles(vector<vector<int>>& grid) {
        edge curr;
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        auto cmp = [](const edge &a, const edge &b){ return (get<2>(a) > get<2>(b)); };
        priority_queue<edge, vector<edge>, decltype(cmp)> pq;

        dist[0][0] = 0;
        pq.push(edge(0,0,0));

        while(!pq.empty()){
            curr = pq.top(); pq.pop();
            visit(grid, dist, curr, pq);
        }

        return dist[n - 1][m - 1];
    }

    vector<vector<int>> paths = { {0,1}, {0,-1}, {1,0}, {-1,0} };

    template <typename PQ>
    void visit(const vector<vector<int>> &grid, vector<vector<int>> &dist, const edge &e, PQ &pq){
        int i = get<0>(e), ni;
        int j = get<1>(e), nj;

        for(const vector<int> &path : paths){
            ni = i + path[0];
            nj = j + path[1];

            if(ni <  0 || nj <  0) continue;
            if(ni >= n || nj >= m) continue;

            // o custo é o mesmo para todos
            // o primeiro caminho já é o menor
            if(dist[ni][nj] != INT_MAX) continue;

            dist[ni][nj] = dist[i][j] + grid[ni][nj];
            pq.push({ni, nj, dist[ni][nj]});
        }
    }
};
