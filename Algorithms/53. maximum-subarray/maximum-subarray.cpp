/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * Method: Kadane's Algorithm
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0) return 0;
        if (len == 1) return nums[0];

        // Kadane's Algorithm: O(n)
        int sum = 0;
        int ans = nums[0];
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }

        return ans;
    }
};
// @lc code=end
