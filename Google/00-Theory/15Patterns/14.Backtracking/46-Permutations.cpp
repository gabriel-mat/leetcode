// 
// O(N * N!)
//

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        backtrack(temp, nums);
        return ans;
    }
    
    void backtrack(vector<int> &temp, vector<int> &nums){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int n : nums){
            auto contains = find(temp.begin(), temp.end(), n);
            if(contains != temp.end()) continue;

            temp.push_back(n);
            backtrack(temp, nums);
            temp.pop_back();
        }
    }
};


//
// Modelo:
//

public List<List<Integer>> permute(int[] nums) {
   List<List<Integer>> list = new ArrayList<>();
   backtrack(list, new ArrayList<>(), nums);
   return list;
}

private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums){
   if(tempList.size() == nums.length){
      list.add(new ArrayList<>(tempList));
   } else{
      for(int i = 0; i < nums.length; i++){ 
         if(tempList.contains(nums[i])) continue; // element already exists, skip
         tempList.add(nums[i]);
         backtrack(list, tempList, nums);
         tempList.remove(tempList.size() - 1);
      }
   }
} 
