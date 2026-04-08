/*
 * Edge cases:
 * 1- Array CANNOT be empty
 */


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      
      for(int zero_pointer = 0, scout = 0; scout < nums.size(); scout++){
          if(nums[zero_pointer])
              zero_pointer++;
          else if(nums[scout])
              swap(nums[zero_pointer++], nums[scout]);
        }
    }
};
