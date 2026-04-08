class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> triangle(numRows);

      triangle[0] = {1};

      for(int row = 1; row < numRows; row++){
          triangle[row].reserve(row + 1);

          triangle[row].push_back(1);
          for(int column = 1; column < row; column++)
            triangle[row].push_back(triangle[row - 1][column - 1] + triangle[row - 1][column]);
          triangle[row].push_back(1);
        }

      return triangle;
    }
};
