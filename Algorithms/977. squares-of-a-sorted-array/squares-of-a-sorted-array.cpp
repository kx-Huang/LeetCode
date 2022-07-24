/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 *
 * Methods: Two Pointers
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // two pointers
        int n = nums.size();
        vector<int> ans(n, 0);
        int left = 0;
        int right = n - 1;

        // compare and sqaure from two sides to middle: O(n)
        for (int k = n - 1; k >= 0; k--) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans[k] = pow(nums[left], 2);
                left++;
            } else {
                ans[k] = pow(nums[right], 2);
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end
