/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * Method: Two Pointers
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        for (int i = 0; i <= right;) {
            // find 0, swap it to the left, move on to next number
            if (nums[i] == 0) swap(nums[i++], nums[left++]);
            // find two, swap it to the right
            // but we don't know what number now after swap
            // so don't move on the next number
            else if (nums[i] == 2)
                swap(nums[i], nums[right--]);
            else
                i++;
        }
    }
};
// @lc code=end
