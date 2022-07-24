/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * Methods: Prefix Sum
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int productFromLeft = 1;
        int productFromRight = 1;
        vector<int> ans(n, 1);

        // keep left and right cumulative product: O(n)
        for (int i = 0; i < n; i++) {
            ans[i] *= productFromLeft;
            productFromLeft *= nums[i];
            ans[n - 1 - i] *= productFromRight;
            productFromRight *= nums[n - 1 - i];
        }
        return ans;
    }
};
// @lc code=end
