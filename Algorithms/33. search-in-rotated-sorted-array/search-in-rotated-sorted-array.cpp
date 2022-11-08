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
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;

            // left < mid < right: normal case
            if (nums[left] < nums[right]) {
                if (target > nums[mid])
                    left = mid + 1;
                else
                    right = mid;
            }
            // right < left < mid: turn-over in right range
            //      left <= target <= mid   left
            //      mid < target            right
            //      target <= right         right
            //      right < target < left   impossible
            else if (nums[mid] >= nums[left]) {
                if (target <= nums[mid] && target >= nums[left])
                    right = mid;
                else if (target > nums[mid] || target <= nums[right])
                    left = mid + 1;
                else
                    return -1;
            }
            // mid < right < left: turn-over in left range
            //      mid <= target <= right  right
            //      target < mid            left
            //      left <= target          left
            //      right < target < left   impossible
            else if (nums[mid] < nums[right]) {
                if (target <= nums[right] && target >= nums[mid])
                    left = mid + 1;
                else if (target >= nums[left] || target < nums[mid])
                    right = mid;
                else
                    return -1;
            }
        }

        return nums[left] == target ? left : -1;
    }
};
// @lc code=end
