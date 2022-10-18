/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * Method: Dynamic Programming
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector(n, 1));

        // time and space complexity: O(m*n)
        // can be optimized to O(1) space
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m - 1][n - 1];
    }
};
// @lc code=end
