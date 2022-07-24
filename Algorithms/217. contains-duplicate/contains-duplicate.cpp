/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * Methods:
 * Data Structure: Hash Table
 *
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        // Solution 1: check if any insertion to set fails: O(n)
        for (int i = 0; i < nums.size(); i++)
            if (s.insert(nums[i]).second == false) return true;
        return false;

        // Solution 2: Compare size after constructing set // O(n)
        // return nums.size() > unordered_set<int>(nums.begin(), nums.end()).size();
    }
};
// @lc code=end
