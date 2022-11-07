/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * Method: Prefix Sum, Two Pointers
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if (n <= 0) return 0;
        if (n == 1) return nums[0];

        int left = 0;
        int right = 0;
        int ans = nums[0];

        // O(n)
        for (int i = 0; i < n; i++) {
            left = (left == 0 ? 1 : left) * nums[i];
            right = (right == 0 ? 1 : right) * nums[n - i - 1];
            ans = max(ans, max(left, right));
        }

        return ans;
    }
};
// @lc code=end
