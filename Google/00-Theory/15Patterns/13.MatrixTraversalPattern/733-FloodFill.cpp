class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int r, c;
       int sColor = image[sr][sc];
       vector<int> curr;
       queue<vector<int>> queue({{sr, sc}});
       vector<vector<int>> paths = {{1,0} , {-1,0}, {0,1}, {0,-1}};
       
       while(!queue.empty()){
           curr = queue.front(); queue.pop();

           if(image[curr[0]][curr[1]] == color) continue;
           image[curr[0]][curr[1]] = color;

           for(const vector<int> &path : paths){
               r = curr[0] + path[0];
               c = curr[1] + path[1];

               if(r >= 0 && c >= 0 && r < image.size() && c < image[0].size() && image[r][c] == sColor)
                   queue.push({r, c});
           }
       }

       return image;
    }
};
