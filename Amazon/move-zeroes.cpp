#include <vector>

using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int l, r, size = nums.size();

        for (l = 0, r = 0; r < size; r++)
        {
            if (!nums[r])
                continue;

            swap(nums[l], nums[r]);
            l++;
        }
    }
};