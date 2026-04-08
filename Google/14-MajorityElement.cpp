/*
 * Constraints:
 * 1 - The array cannot be empty
 * 2 - There is always a majority element
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int majority = nums[0], counter = 0;

      for(int num : nums){
          if(!counter)
              majority = num;

          if(majority == num)
            counter++;
          else
            counter--;
        }

      return majority;
    }
};
