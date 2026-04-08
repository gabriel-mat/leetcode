class NumArray {
public:
    NumArray(vector<int>& nums) : nums(nums) {
        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
    }

    int sumRange(int left, int right) {
        int a, b;

        a = nums[right];
        b = left < 1 ? 0 : nums[left - 1];

        return a - b;
    }

private:
    vector<int> &nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
