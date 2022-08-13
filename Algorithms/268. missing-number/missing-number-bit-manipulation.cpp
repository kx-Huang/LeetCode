/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * Methods: Bit Manipulation
 * Data Structure: Array
 *
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        // a^b^b=a, index and nums cancel out if nums exist
        //  0^a=a, the answer is the index not cancelled out
        for (int i = 0; i < nums.size(); i++) ans = ans ^ i ^ nums[i];
        return ans;
    }
};
// @lc code=end
