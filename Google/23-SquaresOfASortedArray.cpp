/*
 * Constraints:
 * 1 - The array cannot be empty
 * 2 - Integers can be negative!
 */


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      vector<int> solutionArray(nums.size());

      for(int left = 0, right = nums.size() - 1, i = nums.size() - 1; i >= 0; i--){
          if(std::abs(nums[left]) >= std::abs(nums[right]))
              solutionArray[i] = std::pow(nums[left++], 2);
          else
              solutionArray[i] = std::pow(nums[right--], 2);
        }

      return solutionArray;
    }
};
