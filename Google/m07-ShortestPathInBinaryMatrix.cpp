class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int column = grid[0].size();

        if(grid[0][0] || grid[row - 1][column - 1]) return -1;

        queue<pair<int, int>> q;
        vector<vector<int>> dist(row, vector<int>(column, -1));

        vector<vector<int>> paths = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};

        q.push({0,0});
        dist[0][0] = 1;

        while(!q.empty()){
            auto cr = q.front(); q.pop();

            for(const vector<int> &path : paths){
                int ni = cr.first + path[0];
                int nj = cr.second + path[1];

                if(ni < 0 || nj < 0) continue;
                if(ni >= row || nj >= column) continue;
                if(grid[ni][nj]) continue;

                if(dist[ni][nj] != -1) continue;
                dist[ni][nj] = dist[cr.first][cr.second] + 1;
                q.push({ni, nj});
            }
        }

        return dist[row - 1][column - 1];
    }
};
