class Solution {
public:
    vector<vector<int>> paths = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;

        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    counter++;
                }

        return counter;
    }

    void dfs(vector<vector<char>> &grid, int r, int c){
        grid[r][c] = '0';

        int nr, nc;

        for(const vector<int> &path : paths){
            nr = r + path[0];
            nc = c + path[1];

            if(nr < 0 || nc < 0) continue;
            if(nr >= grid.size() || nc >= grid[0].size()) continue;

            if(grid[nr][nc] == '1') dfs(grid, nr, nc);
        }
    }
};
