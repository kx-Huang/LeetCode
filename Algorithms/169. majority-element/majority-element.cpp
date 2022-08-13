/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * Method: Boyer–Moore Majority Vote Algorithm
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = INT_MAX;
        int count = 0;

        // Boyer–Moore majority vote algorithm: O(n)
        for (int c : nums) {
            if (c == candidate)
                count++;
            else if (count == 0)
                candidate = c;
            else
                count--;
        }

        return candidate;
    }
};
// @lc code=end
