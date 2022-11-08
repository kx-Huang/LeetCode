/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * Method: Two Pointers
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        if (len <= 1) return 0;

        int left = 0;
        int right = len - 1;
        int ans = 0;
        int h = 0;

        // two pointers: O(n)
        while (left < right) {
            h = min(height[left], height[right]);
            ans = max(ans, h * (right - left));
            // move left and right to middle
            // we only need if both left and right are higher
            while (left < right && height[left] <= h) left++;
            while (left < right && height[right] <= h) right--;
        }
        return ans;
    }
};
// @lc code=end
