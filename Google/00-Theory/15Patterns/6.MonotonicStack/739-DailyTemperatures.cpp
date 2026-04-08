class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int currTemp;
        stack<int> stk;
        vector<int> ans(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); ++i){
            currTemp = temperatures[i];

            while(!stk.empty() && currTemp > temperatures[stk.top()])
                ans[stk.top()] = (i - stk.top()), stk.pop();

            stk.push(i);
        }

        return ans;
    }
};
