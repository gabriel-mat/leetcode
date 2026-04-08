class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;

        while(left <= right){
            mid = (right - left) / 2 + left;

            if(nums[mid] == target) return mid;

            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target <= nums[mid]) right = mid - 1;
                else left = mid + 1;
                continue;
            }

            if(nums[mid] <= target && target <= nums[right]) left = mid + 1;
            else right = mid - 1;
        }

        return -1;
    }
};
