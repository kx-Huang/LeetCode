/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * Methods: Binary Search
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // Binary search: O(logn)
        while (left <= right) {
            // prevent overflow
            int mid = left + (right - left) / 2;

            // search left part if target is larger
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
// @lc code=end
