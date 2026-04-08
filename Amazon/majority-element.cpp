#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/*
    Solução boa, com O(n) em tempo
    Mas é O(n) em espaço pelo hashmap
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();

        int threshold = n / 2;
        unordered_map<int, int> counts;

        for (int x : nums)
            if (++counts[x] > threshold)
                return x;

        return -1;
    }
};