class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int insert_pos = 1;
        for (int scout = 1; scout < nums.size(); scout++) {
            if (nums[scout] != nums[scout - 1]) {
                nums[insert_pos++] = nums[scout];
            }
        }
        return insert_pos;
    }
};
