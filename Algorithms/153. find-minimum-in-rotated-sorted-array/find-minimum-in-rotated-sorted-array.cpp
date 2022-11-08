/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * Method: Binary Search
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            // no rotation in this range
            if (nums[left] < nums[right]) return nums[left];
            // compute mid
            int mid = left + (right - left) / 2;
            // min in left range
            // e.g. [6,7,0,1,2,3,4,5]
            if (nums[left] > nums[mid]) {
                right = mid;
            }
            // min in right range
            // e.g. [3,4,5,6,0,1,2]
            else {
                left = mid + 1;
            }
        }

        return nums[left];
    }
};
// @lc code=end
