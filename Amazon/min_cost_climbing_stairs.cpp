#include <vector>
#include <iostream>

using namespace std;

/*
    Solução mais óbvia ( O(2^n) )
    Inviável sem memoization - TLE
*/

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        return min(cost_rec(cost, 0, 0), cost_rec(cost, 1, 0));
    }

    int cost_rec(vector<int> &cost, int init, int counter)
    {
        if(init >= cost.size())
            return counter;

        counter += cost[init];
        return min(cost_rec(cost, init + 1, counter), cost_rec(cost, init + 2, counter));
    }
};