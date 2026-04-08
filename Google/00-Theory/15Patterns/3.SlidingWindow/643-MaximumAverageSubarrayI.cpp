class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left = 0, right = k - 1, curr, currMax = 0;

        for(int i = left; i <= right; ++i)
            currMax += nums[i];

        curr = currMax;

        while(right < nums.size() - 1){
            curr -= nums[left++];
            curr += nums[++right];

            currMax = max(curr, currMax);
        }

        return (currMax / (double) k);
    }
};
