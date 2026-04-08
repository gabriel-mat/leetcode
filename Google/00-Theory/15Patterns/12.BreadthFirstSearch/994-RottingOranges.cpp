class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int,int>> dir = { {1,0}, {-1,0}, {0,1}, {0,-1} };

        int time = 0;
        int fresh = 0;

        auto bfs = [&]() {
            queue<pair<int,int>> q;

            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(grid[i][j] == 2) q.push({i,j});
                    else if(grid[i][j] == 1) fresh++;
                }
            }

            while(!q.empty()){
                int size = q.size();
                bool infected = false;

                while(size--){
                    auto [i,j] = q.front();
                    q.pop();

                    for(auto [dx,dy] : dir){
                        int x = i + dx;
                        int y = j + dy;

                        if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1){
                            grid[x][y] = 2;
                            q.push({x,y});
                            fresh--;
                            infected = true;
                        }
                    }
                }

                if(infected) time++;
            }
        };

        bfs();

        return !fresh ? time : -1;
    }
};
