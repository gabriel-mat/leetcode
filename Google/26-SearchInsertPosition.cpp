class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int left, mid, right;

      left = 0;
      right = nums.size() - 1;

      while(left <= right){
          mid = (right - left) / 2 + left;

          if(nums[mid] == target)
            return mid;

          if(nums[mid] < target)
            left = mid + 1;
          else
            right = mid - 1;
        }

      // a posição em que o elemento deveria estar é o próprio left
      // mas o cálculo abaixo também funciona

      if(nums[mid] < target)
        return mid + 1;
      return mid;
    }
};
