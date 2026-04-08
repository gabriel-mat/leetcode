class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxConsecutive = 0;
        unordered_set<int> set(nums.begin(), nums.end());

        for(int n : set){
            if(set.find(n - 1) != set.end()) // não é o começo de uma sequência
                continue;

            int counter = 1;
            while(set.find(++n) != set.end())
                counter++;

            maxConsecutive = std::max(counter, maxConsecutive);
        }

        return maxConsecutive;
    }
};
