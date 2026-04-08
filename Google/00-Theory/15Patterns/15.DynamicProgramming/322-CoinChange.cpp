class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        int memo[n + 1]; memo[0] = 0;
        sort(begin(coins), end(coins));

        for (int i = 1; i <= n; ++i) {
            memo[i] = INT_MAX;

            for (int coin : coins) {
                if (i - coin < 0) break;
                if (memo[i - coin] != INT_MAX) memo[i] = min(memo[i], 1 + memo[i - coin]);
            }
        }

        return memo[n] == INT_MAX ? -1 : memo[n];
    }
};
