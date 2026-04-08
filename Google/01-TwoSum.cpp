class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;

        for(int pos = 0; pos < nums.size(); ++pos){
          if(map.find(target - nums[pos]) != map.end())
            return {map[target - nums[pos]], pos};

          map[nums[pos]] = pos;
        }

        return {};
    }
};
