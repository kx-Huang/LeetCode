/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
   public:
    bool containsDuplicate(vector<int>& nums) {
        // Solution 1: check if any insertion to set fails
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
            if (s.insert(nums[i]).second == false) return true;
        return false;

        // Solution 2: Compare size after constructing set
        // return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
    }
};
// @lc code=end
