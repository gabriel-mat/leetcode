#include <vector>
#include <iostream>

using namespace std;

/*
    Solução ótima - O(n)
    como os passos são restritos (1 ou 2)
    é possível calcular usando apenas os 2 últimos degraus
    -> como em Fibonacci ou Pascal
*/

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();

        for (int i = 2; i < n; i++)
            cost[i] += min(cost[i - 1], cost[i - 2]);

        return min(cost[n - 1], cost[n - 2]);
    }
};