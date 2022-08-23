/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 *
 * Method: Dynamic Programming
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int m = nums1.size();
        int n = nums2.size();

        // dp[i][j]: length of the longest common suffix between:
        // first i nums in nums1 and first j nums in nums2
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // initial condition: dp[0][0] = 0
        dp[0][0] = 0;

        // relation: dp[i+1][j+1] = dp[i][j] + 1 if nums[i] == nums[k]
        // time complexity: O(m*n)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i + 1][j + 1] = nums1[i] == nums2[j] ? dp[i][j] + 1 : 0;
                ans = max(ans, dp[i + 1][j + 1]);
            }
        }
        return ans;
    }
};
// @lc code=end
