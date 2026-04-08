class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;

        while(left < right){
            mid = (right - left) / 2 + left;

            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }

        return nums[left];
    }
};
