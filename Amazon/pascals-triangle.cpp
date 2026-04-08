#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> triangle(numRows);

        for (int row = 0; row < numRows; row++)
        {
            triangle[row].resize(row + 1);

            triangle[row][0] = 1;
            for (int column = 1, l = 0, r = 1; column < row; column++, l++, r++)
                triangle[row][column] = triangle[row - 1][l] + triangle[row - 1][r];
            triangle[row][row] = 1;
        }

        return triangle;
    }
};