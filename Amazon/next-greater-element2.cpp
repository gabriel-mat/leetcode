#include <stack>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
    Monotonic stack approach - O(n)
     -> elements are kept in either increasing (MIS) or decreasing order (MDS)
*/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> stk;
        vector<int> ans;
        unordered_map<int, int> map;

        for (int num : nums2)
        {
            while (!stk.empty() && stk.top() < num)
            {
                map[stk.top()] = num;
                stk.pop();
            }

            stk.push(num);
        }

        for (int num : nums1)
            ans.push_back(map.count(num) ? map[num] : -1);

        return ans;
    }
};