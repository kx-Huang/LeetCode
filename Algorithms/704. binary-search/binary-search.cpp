/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 *
 * Method: Binary Search
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // Binary search: O(logn)
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
// @lc code=end
