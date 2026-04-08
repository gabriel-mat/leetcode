class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> hashmap;

        for(int n : nums2){
            while(!stk.empty() && n > stk.top())
                hashmap[stk.top()] = n, stk.pop();

            stk.push(n);
        }

        vector<int> ans;
        ans.reserve(nums1.size());

        for(int n : nums1){
            auto find = hashmap.find(n);

            if(find == hashmap.end())
                ans.push_back(-1);
            else
                ans.push_back(find->second);
        }

        return ans;
    }
};
