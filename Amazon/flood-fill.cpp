#include <vector>
#include <iostream>
#include <functional>

using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int oldColor = image[sr][sc];
        
        if (oldColor == color)
            return image;

        int rows = image.size(), cols = image[0].size();

        function<void(int, int)> dfs = [&](int r, int c)
        {
            if (r < 0 || r >= rows || c < 0 || c >= cols || image[r][c] != oldColor)
                return;

            image[r][c] = color;

            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
        };

        dfs(sr, sc);
        return image;
    }
};