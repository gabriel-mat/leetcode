
// Solução mais trivial (bsearch em cada row)
// O(M * log(N))
//

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left, mid, right;
        int size = matrix[0].size();

        for(const vector<int> &row : matrix){
            left = 0, right = size - 1;

            while(left <= right){
                mid = (right - left) / 2 + left;
                
                if(row[mid] == target) return true;

                if(row[mid] < target) left = mid + 1;
                else right = mid - 1;
            }
        }

        return false;
    }
};


//
// Solução usando árvore (otimiza porque vira apenas 1 estrutura ordenada)
// O(N + M)
//

class Solution {
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;

        while(col >= 0 && row < matrix.size()) {
            if(target == matrix[row][col]) return true;

            if(target < matrix[row][col]) col--;
            else row++;
        }

        return false;
    }
};
