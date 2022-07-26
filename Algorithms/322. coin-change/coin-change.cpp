/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Dynamic Programming
 *
 * Methods: Backtracking
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // $0 needs no coin
        if (amount == 0) return 0;

        // $n needs dp[n] coins
        vector<int> dp(amount + 1, amount + 1);

        // initial condition: $0 needs no coin
        dp[0] = 0;

        // relation: $(n+coin) needs 1 more coin
        for (int coin : coins)
            for (int i = coin; i <= amount; i++)
                dp[i] = min(dp[i], dp[i - coin] + 1);

        return dp[amount] <= amount ? dp[amount] : -1;
    }
};
// @lc code=end
