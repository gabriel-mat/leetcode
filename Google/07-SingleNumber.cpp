/*
 * Edge cases:
 * 1 - The array could contain just 1 element, mask variable should be initialized to 0
 * 2 - The array cannot be empty
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask = 0;

        for(int num : nums)
          mask ^= num;

        return mask;
    }
};
