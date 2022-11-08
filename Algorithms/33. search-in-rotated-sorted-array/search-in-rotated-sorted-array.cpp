/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * Method: Binary Search
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len <= 0) return -1;
        if (len == 1) return target == nums[0] ? 0 : -1;

        int left = 0;
        int right = len - 1;

        // binary search: O(logn)
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // find match
            if (nums[mid] == target) return mid;

            // see 33.png for illustration
            // determine target relationships by comparing left and middle point
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        // no match found after binary search
        return -1;
    }
};
// @lc code=end
