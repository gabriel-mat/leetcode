#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans(nums1.size());
        unordered_map<int, int> map;

        for (int i = 0; i < nums2.size(); i++)
            map[nums2[i]] = i;

        for (int i = 0; i < nums1.size(); i++)
        {
            ans[i] = -1;

            for (int j = map[nums1[i]] + 1; j < nums2.size(); j++)
            {
                if (nums2[j] > nums1[i])
                {
                    ans[i] = nums2[j];
                    break;
                }
            }
        }

        return ans;
    }
};