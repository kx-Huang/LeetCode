/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 *
 * Method: Mathematical Optimization
 * Data Structure:
 *
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = (m - 1) + (n - 1);
        int k = m < n ? m - 1 : n - 1;

        // time complexity: O(min(m,n))
        // combinatorial number:
        //      kCn = n!/(k!(n−k)!)
        //          =(n*(n−1)*(n−2)*...*(n−k+1))/k!
        // Notes:
        //      1. prevent overflow
        //      2. do exact division (no decimal)
        long long int ans = 1;
        for (int i = 1; i <= k; i++) ans = ans * (N - i + 1) / i;
        return ans;
    }
};
// @lc code=end
