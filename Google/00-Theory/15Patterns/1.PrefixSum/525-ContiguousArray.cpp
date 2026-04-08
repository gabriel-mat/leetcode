class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return 0;

        int maxL = 0;
        unordered_map<int, int> hashMap; // sum -> index
        hashMap[0] = -1;

        nums[0] = nums[0] ? 1 : -1;
        hashMap[nums[0]] = 0;

        for(int i = 1; i < nums.size(); i++){
            nums[i] = nums[i - 1] + (2 * nums[i] - 1);

            auto find = hashMap.find(nums[i]);

            if(find != hashMap.end())
                maxL = max(maxL, i - find->second);
            else
                hashMap[nums[i]] = i;
        }

        return maxL;
    }
};


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        hashMap[0] = -1;
        int maxL = 0, soma = 0;

        for (int i = 0; i < nums.size(); i++) {
            soma += (2 * nums[i]) - 1;

            auto it = hashMap.find(soma);

            if (it != hashMap.end())
                maxL = max(maxL, i - it->second);
            else
                hashMap[soma] = i;
        }

        return maxL;
    }
};
