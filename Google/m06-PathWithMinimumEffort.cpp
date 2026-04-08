class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            vector<int> current = pq.top();
            pq.pop();

            int d = current[0];
            int r = current[1];
            int c = current[2];

            if (d > dist[r][c]) continue;
            if (r == rows - 1 && c == cols - 1) return d;

            for (auto &dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int effort = max(d, abs(heights[r][c] - heights[nr][nc]));

                    if (effort < dist[nr][nc]) {
                        dist[nr][nc] = effort;
                        pq.push({effort, nr, nc});
                    }
                }
            }
        }

        return 0;
    }
};
