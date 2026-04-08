class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxConsecutives = 0, counter = 0;

        for(int num : nums){
            if(num)
              counter++;
            else{
              maxConsecutives = std::max(counter, maxConsecutives);
              counter = 0;
            }
          }

        return std::max(counter, maxConsecutives);
    }
};
