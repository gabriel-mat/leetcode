class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }

    void backtrack(vector<int> &nums, int n){
        ans.push_back(temp);

        for(int i = n; i < nums.size(); ++i){
            temp.push_back(nums[i]);
            backtrack(nums, i);
            temp.pop_back();
        }
    }
};


// Modelo

public List<List<Integer>> subsets(int[] nums) {
    List<List<Integer>> list = new ArrayList<>();
    Arrays.sort(nums);
    backtrack(list, new ArrayList<>(), nums, 0);
    return list;
}

private void backtrack(List<List<Integer>> list , List<Integer> tempList, int [] nums, int start){
    list.add(new ArrayList<>(tempList));
    for(int i = start; i < nums.length; i++){
        tempList.add(nums[i]);
        backtrack(list, tempList, nums, i + 1);
        tempList.remove(tempList.size() - 1);
    }
}
