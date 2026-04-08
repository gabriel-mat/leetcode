class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int counter = 0;
        unordered_map<int, int> seen; // sum -> counter of that sum

        // seen.insert(0);

        for(int sum = 0, i = 0; i < nums.size(); i++){
            sum += nums[i];

            if(sum == k)
                counter++;
            if(seen.count(sum - k))
                counter += seen[sum - k];
            
            seen[sum]++;
        }

        return counter;
    }
};

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int counter = 0;
        unordered_map<int, int> seen; // sum -> counter of that sum

        seen[0] = 1;

        for(int sum = 0, i = 0; i < nums.size(); i++){
            sum += nums[i];

           if (seen.find(sum - k) != seen.end())
                counter += seen[sum - k];

            seen[sum]++;
        }

        return counter;
    }
};
