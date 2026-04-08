class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int left = 0, right = numbers.size() - 1; left < right; ){
                int sum = numbers[left] + numbers[right];

                if(sum == target) return {left + 1, right + 1};
                
                if(sum < target)
                    left++;
                else
                    right--;
        }

        return {0,0};
    }
};
