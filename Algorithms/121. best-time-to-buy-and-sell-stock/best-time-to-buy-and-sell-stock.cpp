/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * Method: Iterative Traversal
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        int curMin = prices[0];
        int ans = 0;

        // O(n)
        for (int i = 1; i < prices.size(); i++) {
            curMin = min(curMin, prices[i]);
            ans = max(ans, prices[i] - curMin);
        }

        return ans;
    }
};
// @lc code=end
